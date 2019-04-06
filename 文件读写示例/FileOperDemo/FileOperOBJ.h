// FileOperOBJ.h: interface for the CFileOperOBJ class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEOPEROBJ_H__7AFC1A38_1D63_4487_A47D_3C559BC17F0C__INCLUDED_)
#define AFX_FILEOPEROBJ_H__7AFC1A38_1D63_4487_A47D_3C559BC17F0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////////////////////////////////////////

//����  ְ�Ʊ��  ����    ����
struct TeacherStcT
{
	char   Name[16];
	short  ProfessionNo; //[0,1,2,3,4]
	short  WorkYears;
	short  Ages;

	TeacherStcT()
	{
		memset(this, '\0', sizeof(TeacherStcT));
	}
};

//�����ñȽϺ���ָ������.
typedef int (*MySortFunc)(const void *elem1, const void *elem2); 

///////////////////////////////////////////////////////////////////////////////////////////////

class CFileOperOBJ  
{
public:
	CFileOperOBJ();
	virtual ~CFileOperOBJ();

//Attributes.
private:

	TeacherStcT *m_pTeacherSet;
	long         m_SetNum;

//Operations.
private:

	void ClearArray(void);

public:

	//���벢�����ļ�.
	bool ReadFileToArray(LPCTSTR InFileName);

	//���սṹ��Ա��������(1/2/3/4: ����/ְ�Ʊ��/����/����)
	bool SortArrayByMemberNo(short MemberNo, bool IsDescend);

	//��������д���ļ�.
	bool WriteArrayToFile(LPCTSTR OutFileName);

};

#endif // !defined(AFX_FILEOPEROBJ_H__7AFC1A38_1D63_4487_A47D_3C559BC17F0C__INCLUDED_)
