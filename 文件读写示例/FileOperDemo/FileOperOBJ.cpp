#include "stdafx.h"
#include "FileOperOBJ.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////

//�������ֽ�������.
int DescendName(TeacherStcT *pTeach1, TeacherStcT *pTeach2)
{
	int bResult=_stricmp(pTeach1->Name, pTeach2->Name);
	return (!bResult) ? 0 : ((bResult<0) ? 1 : -1);
}

//����������������.
int AscendName(TeacherStcT *pTeach1, TeacherStcT *pTeach2)
{
	return _stricmp(pTeach1->Name, pTeach2->Name);
}

//���չ��併������.
int DescendWorkYears(TeacherStcT *pTeach1, TeacherStcT *pTeach2)
{
	return (pTeach1->WorkYears==pTeach2->WorkYears) ? 0 : ((pTeach1->WorkYears<pTeach2->WorkYears) ? 1 : -1);
}

//���չ�����������.
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
#define MAX_FILED_NUM     4        //�ļ�ÿ���ֶεĸ������ɸ���ʵ���ļ���ʽ����!

//���벢�����ļ�.
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

	//�����ı��ֶ���ʱ������.
	pArraySet=new char[MAX_FILED_NUM][256];
	if(!pArraySet) return bResult;

	m_pTeacherSet=new TeacherStcT[MAX_SET_NUM];
	if(!m_pTeacherSet) goto END;

	if(!InFile.Open(InFileName, CFile::modeRead|CFile::typeText)) goto END;
	//���˱�����.
	InFile.ReadString(Text);

	while(InFile.ReadString(Text))
	{
		if(m_SetNum>=MaxSetNum)  //��������.
		{
			MaxSetNum+=MAX_SET_NUM;
			TeacherStcT *pTemp=NULL;
			pTemp=new TeacherStcT[MaxSetNum];
			if(!pTemp) goto END;
			memcpy(pTemp, m_pTeacherSet, m_SetNum*sizeof(TeacherStcT)); //����ԭ������Ԫ��.
			delete[] m_pTeacherSet;
			m_pTeacherSet=pTemp;
		}

		//���н����ı��ļ�, �����ֶ���ʱ������.
		p=Text.GetBuffer(Text.GetLength()+1);
		//��Ӧ��: ����  ְ�Ʊ��  ����    ����
		sscanf(p, "%s %s %s %s", pArraySet[0], pArraySet[1], pArraySet[2], pArraySet[3]);  
		Text.ReleaseBuffer();
   
		//����
		strcpy(m_pTeacherSet[m_SetNum].Name, pArraySet[0]);
		//ְ�Ʊ��.
	    m_pTeacherSet[m_SetNum].ProfessionNo=atoi(pArraySet[1]);
		//����.
		m_pTeacherSet[m_SetNum].WorkYears=atoi(pArraySet[2]);
		//����.
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

//���սṹ��Ա��������(1/2/3/4: ����/ְ�Ʊ��/����/����)
bool CFileOperOBJ::SortArrayByMemberNo(short MemberNo, bool IsDescend)
{
	if(!m_pTeacherSet || m_SetNum<1) return false;

	MySortFunc pFunc=NULL;

	switch(MemberNo)
	{
		case 1:
			pFunc=(MySortFunc)(IsDescend ? DescendName : AscendName);
			break;

		case 2:   //��������!
			break;

		case 3:
			pFunc=(MySortFunc)(IsDescend ? DescendWorkYears : AscendWorkYears);
			break;

		case 4:   //��������!
			break;

		default:
			break;
	}

	//���ǣ���ؼ����������ʵ��?
	//���磺�Ȱ�ְ�Ʊ���ţ�ְͬ�ư��ַ������ţ�ͬ���䰴������, ��������!

	if(pFunc!=NULL)
	{
		qsort((void *)m_pTeacherSet, m_SetNum, sizeof(TeacherStcT), pFunc);
	}

	return true;
}

//��������д���ļ�.
bool CFileOperOBJ::WriteArrayToFile(LPCTSTR OutFileName)
{
	if(lstrlen(OutFileName)<1 || !m_pTeacherSet || m_SetNum<1) return false;

	CStdioFile OutFile;
	CString    Text=_T("");
	long       i;

	if(!OutFile.Open(OutFileName, CFile::modeCreate|CFile::modeWrite|CFile::typeText)) return false;

	//���������.
	OutFile.WriteString(_T("����  ְ�Ʊ��   ����    ����\n"));

	for(i=0; i<m_SetNum; i++)
	{
		Text.Format("%s\t%d\t%d\t%d\n", m_pTeacherSet[i].Name, m_pTeacherSet[i].ProfessionNo,
			                            m_pTeacherSet[i].WorkYears, m_pTeacherSet[i].Ages);
		OutFile.WriteString(Text);
	}

	OutFile.Close();
	return true;
}