
// xialiangwei10View.cpp : implementation of the Cxialiangwei10View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "xialiangwei10.h"
#endif

#include "xialiangwei10Doc.h"
#include "xialiangwei10View.h"
#include "MAIN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cxialiangwei10View

IMPLEMENT_DYNCREATE(Cxialiangwei10View, CView)

BEGIN_MESSAGE_MAP(Cxialiangwei10View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cxialiangwei10View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CALCULATOR_CALCULATION, &Cxialiangwei10View::OnCalculation)
END_MESSAGE_MAP()

// Cxialiangwei10View construction/destruction

Cxialiangwei10View::Cxialiangwei10View()
{
	// TODO: add construction code here

}

Cxialiangwei10View::~Cxialiangwei10View()
{
}

BOOL Cxialiangwei10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cxialiangwei10View drawing

void Cxialiangwei10View::OnDraw(CDC* /*pDC*/)
{
	Cxialiangwei10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cxialiangwei10View printing


void Cxialiangwei10View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cxialiangwei10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cxialiangwei10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cxialiangwei10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cxialiangwei10View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cxialiangwei10View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cxialiangwei10View diagnostics

#ifdef _DEBUG
void Cxialiangwei10View::AssertValid() const
{
	CView::AssertValid();
}

void Cxialiangwei10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cxialiangwei10Doc* Cxialiangwei10View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cxialiangwei10Doc)));
	return (Cxialiangwei10Doc*)m_pDocument;
}
#endif //_DEBUG


// Cxialiangwei10View message handlers


void Cxialiangwei10View::OnCalculation()
{
	// TODO: Add your command handler code here
	MAIN main_a;
	main_a.DoModal();
}
