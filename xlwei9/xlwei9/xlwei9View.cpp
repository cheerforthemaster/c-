
// xlwei9View.cpp : implementation of the Cxlwei9View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "xlwei9.h"
#endif

#include "xlwei9Doc.h"
#include "xlwei9View.h"
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxlwei9View

IMPLEMENT_DYNCREATE(Cxlwei9View, CView)

BEGIN_MESSAGE_MAP(Cxlwei9View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cxlwei9View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_GETINFORMATION_INPUTINFORMATION, &Cxlwei9View::OnGetinformation)
	ON_COMMAND(ID_FILE_NEW, &Cxlwei9View::OnFileNew)
	ON_COMMAND(ID_GETINFORMATION_READINFORMATION, &Cxlwei9View::OnReadinformation)
	ON_COMMAND(ID_GETINFORMATION_CHANGEINFORMATION, &Cxlwei9View::OnChangeinformation)
	ON_COMMAND(ID_GETINFORMATION_LOCATION, &Cxlwei9View::OnGetinformationLocation)
END_MESSAGE_MAP()

// Cxlwei9View construction/destruction

Cxlwei9View::Cxlwei9View()
{
	// TODO: add construction code here

}

Cxlwei9View::~Cxlwei9View()
{
}

BOOL Cxlwei9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cxlwei9View drawing

void Cxlwei9View::OnDraw(CDC* /*pDC*/)
{
	Cxlwei9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cxlwei9View printing


void Cxlwei9View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cxlwei9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cxlwei9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cxlwei9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cxlwei9View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxlwei9View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxlwei9View diagnostics

#ifdef _DEBUG
void Cxlwei9View::AssertValid() const
{
	CView::AssertValid();
}

void Cxlwei9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cxlwei9Doc* Cxlwei9View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxlwei9Doc)));
	return (Cxlwei9Doc*)m_pDocument;
}
#endif //_DEBUG


// Cxlwei9View message handlers
struct DataPoints
{
	long mounth;
	long day;
	double x;
	double y;
};

DataPoints dp= {3,20,1.23,3.69};
fstream xlw;

void Cxlwei9View::OnFileNew()
{
	// TODO: Add your command handler code here
	xlw.open("xlw.dat");
	xlw.close();
}


void Cxlwei9View::OnGetinformation()
{
//	DataPoints dp = { 3,20,1.23,3.69 };
	xlw.open("xlw.dat",ios::out|ios::binary);
	xlw.write((char*)(&dp),sizeof(dp));
	xlw.close();
}


void Cxlwei9View::OnReadinformation()
{
//	DataPoints dp = { 3,20,1.23,3.69 };
	xlw.open("xlw.dat",ios::in|ios::binary);
	xlw.read((char*)(&dp), sizeof(dp));
	xlw.close();
}



void Cxlwei9View::OnChangeinformation()
{
//	DataPoints dp = { 3,20,1.23,3.69 };
	dp = {3,27,3.14,4.130};
	xlw.open("xlw.dat",ios::out|ios::binary);
	xlw.write((char*)(&dp), sizeof(dp));
	xlw.close();
}


void Cxlwei9View::OnGetinformationLocation()
{
//	DataPoints dp = { 3,20,1.23,3.69 };
	xlw.open("xlw.dat",ios::out|ios::binary|ios::in);
	xlw.seekp(16);//两个long，一个double，16个byte
	double y = 3.141590;
	xlw.write((char*)(&y), sizeof(double));
//	xlw.seekg(0);
//	xlw.read((char*)(&dp), sizeof(dp));//测试
	xlw.close();
}
