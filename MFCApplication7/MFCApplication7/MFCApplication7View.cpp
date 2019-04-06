
// MFCApplication7View.cpp : implementation of the CMFCApplication7View class
//
//#include "CPoint.h"
#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication7.h"
#endif

#include "MFCApplication7Doc.h"
#include "MFCApplication7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7View

IMPLEMENT_DYNCREATE(CMFCApplication7View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication7View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApplication7View construction/destruction

CMFCApplication7View::CMFCApplication7View()
{
	// TODO: add construction code here

}

CMFCApplication7View::~CMFCApplication7View()
{
}

BOOL CMFCApplication7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

 //CMFCApplication7View drawing




void CMFCApplication7View::OnDraw(CDC* pDC)
{
	CMFCApplication7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	int a = 200, b = 200;

	for (int i = 0;i <= 100 ; i++)
	{
		
		pDC->SetPixel(a, b, RGB(0, 0, 0));
		++a;
		++b;
	}
	
	for (int i = 0;i <= 100; i++ )
	{
		pDC->SetPixel(a, b, RGB(0, 0, 0));
		++a;
		--b;
	}
}











// CMFCApplication7View printing

BOOL CMFCApplication7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCApplication7View diagnostics

#ifdef _DEBUG
void CMFCApplication7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication7Doc* CMFCApplication7View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication7Doc)));
	return (CMFCApplication7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication7View message handlers
