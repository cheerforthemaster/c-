#include "stdafx.h"
#include "FileOperOBJ.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//按照名字降序排序.
int DescendName(TeacherStcT *pTeach1, TeacherStcT *pTeach2)
{
	int bResult=_stricmp(pTeach1->Name, pTeach2->Name);
	return (!bResult) ? 0 : ((bResult<0) ? 1 : -1);
}

//按照名字升序排序.
int AscendName(TeacherStcT *pTeach1, TeacherStcT *pTeach2)
{
	return _stricmp(pTeach1->Name, pTeach2->Name);
}

//按照工龄降序排序.
int DescendWorkYears(TeacherStcT *pTeach1, TeacherStcT *pTeach2)
{
	return (pTeach1->WorkYears==pTeach2->WorkYears) ? 0 : ((pTeach1->WorkYears<pTeach2->WorkYears) ? 1 : -1);
}

//按照工龄升序排序.
int AscendWorkYears(TeacherStcT *pTeach1, TeacherStcT *pTeach2)
{
	return (pTeach1->WorkYears==pTeach2->WorkYears) ? 0 : ((pTeach1->WorkYears>pTeach2->WorkYears) ? 1 : -1);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

CFileOperOBJ::CFileOperOBJ()
{
	m_pTeacherSet = NULL;
	m_SetNum = 0;
}

CFileOperOBJ::~CFileOperOBJ()
{
	ClearArray();	
}

void CFileOperOBJ::ClearArray()
{
	if(m_pTeacherSet!=NULL) delete[] m_pTeacherSet;
	m_pTeacherSet=NULL;
	m_SetNum = 0;
}

#define MAX_SET_NUM     100
#define MAX_FILED_NUM     4        //文件每行字段的个数，可根据实际文件格式调整!

//读入并解析文件.
bool CFileOperOBJ::ReadFileToArray(LPCTSTR InFileName)
{
	if(lstrlen(InFileName)<1) return false;

	ClearArray();

	CStdioFile   InFile;
	CString      Text=_T("");
	LPTSTR       p;
	long         MaxSetNum=MAX_SET_NUM;
	char         (*pArraySet)[256]=NULL;
	bool         bResult=false;

	//申请文本字段临时缓冲区.
	pArraySet=new char[MAX_FILED_NUM][256];
	if(!pArraySet) return bResult;

	m_pTeacherSet=new TeacherStcT[MAX_SET_NUM];
	if(!m_pTeacherSet) goto END;

	if(!InFile.Open(InFileName, CFile::modeRead|CFile::typeText)) goto END;
	//过滤标题行.
	InFile.ReadString(Text);

	while(InFile.ReadString(Text))
	{
		if(m_SetNum>=MaxSetNum)  //数组增容.
		{
			MaxSetNum+=MAX_SET_NUM;
			TeacherStcT *pTemp=NULL;
			pTemp=new TeacherStcT[MaxSetNum];
			if(!pTemp) goto END;
			memcpy(pTemp, m_pTeacherSet, m_SetNum*sizeof(TeacherStcT)); //复制原有数组元素.
			delete[] m_pTeacherSet;
			m_pTeacherSet=pTemp;
		}

		//逐行解析文本文件, 置于字段临时缓冲区.
		p=Text.GetBuffer(Text.GetLength()+1);
		//对应于: 姓名  职称编号  工龄    年龄
		sscanf(p, "%s %s %s %s", pArraySet[0], pArraySet[1], pArraySet[2], pArraySet[3]);  
		Text.ReleaseBuffer();
   
		//姓名
		strcpy(m_pTeacherSet[m_SetNum].Name, pArraySet[0]);
		//职称编号.
	    m_pTeacherSet[m_SetNum].ProfessionNo=atoi(pArraySet[1]);
		//工龄.
		m_pTeacherSet[m_SetNum].WorkYears=atoi(pArraySet[2]);
		//年龄.
		m_pTeacherSet[m_SetNum].Ages=atoi(pArraySet[3]);

		m_SetNum++;
	}

	InFile.Close();
	bResult=true;

END:

	if(!bResult) ClearArray();

	if(pArraySet!=NULL) delete[] pArraySet;
	pArraySet=NULL;

	return bResult;
}

//按照结构成员进行排序(1/2/3/4: 姓名/职称编号/工龄/年龄)
bool CFileOperOBJ::SortArrayByMemberNo(short MemberNo, bool IsDescend)
{
	if(!m_pTeacherSet || m_SetNum<1) return false;

	MySortFunc pFunc=NULL;

	switch(MemberNo)
	{
		case 1:
			pFunc=(MySortFunc)(IsDescend ? DescendName : AscendName);
			break;

		case 2:   //自行扩充!
			break;

		case 3:
			pFunc=(MySortFunc)(IsDescend ? DescendWorkYears : AscendWorkYears);
			break;

		case 4:   //自行扩充!
			break;

		default:
			break;
	}

	//考虑：多关键字排序如何实现?
	//例如：先按职称编号排，同职称按分房工龄排，同工龄按年龄排, 降序排列!

	if(pFunc!=NULL)
	{
		qsort((void *)m_pTeacherSet, m_SetNum, sizeof(TeacherStcT), pFunc);
	}

	return true;
}

//将排序结果写入文件.
bool CFileOperOBJ::WriteArrayToFile(LPCTSTR OutFileName)
{
	if(lstrlen(OutFileName)<1 || !m_pTeacherSet || m_SetNum<1) return false;

	CStdioFile OutFile;
	CString    Text=_T("");
	long       i;

	if(!OutFile.Open(OutFileName, CFile::modeCreate|CFile::modeWrite|CFile::typeText)) return false;

	//输出标题行.
	OutFile.WriteString(_T("姓名  职称编号   工龄    年龄\n"));

	for(i=0; i<m_SetNum; i++)
	{
		Text.Format("%s\t%d\t%d\t%d\n", m_pTeacherSet[i].Name, m_pTeacherSet[i].ProfessionNo,
			                            m_pTeacherSet[i].WorkYears, m_pTeacherSet[i].Ages);
		OutFile.WriteString(Text);
	}

	OutFile.Close();
	return true;
}