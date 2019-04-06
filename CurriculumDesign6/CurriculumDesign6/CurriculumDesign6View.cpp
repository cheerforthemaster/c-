
// CurriculumDesign6View.cpp : implementation of the CCurriculumDesign6View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CurriculumDesign6.h"
#endif

#include "CurriculumDesign6Doc.h"
#include "CurriculumDesign6View.h"
#include "Add_consumption_record.h"
#include "Add_revenue_record.h"
#include "Add_transfer_record.h"
#include "My_cash_account.h"
#include "BankofChinaaccount.h"
#include "Icbcaccount.h"
#include "Monthly_income_statement.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCurriculumDesign6View

IMPLEMENT_DYNCREATE(CCurriculumDesign6View, CView)

BEGIN_MESSAGE_MAP(CCurriculumDesign6View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCurriculumDesign6View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ACCOUNTINGFUNCTION_ADDCONSUMPTIONRECORD, &CCurriculumDesign6View::OnAddconsumptionrecord)
	ON_COMMAND(ID_ACCOUNTINGFUNCTION_ADDREVENUERECORD, &CCurriculumDesign6View::OnAddrevenuerecord)
	ON_COMMAND(ID_ACCOUNTINGFUNCTION_ADDTRANSFERRECORD, &CCurriculumDesign6View::OnAddtransferrecord)
	ON_COMMAND(ID_VIEWBILL_MYCASHACCOUNT, &CCurriculumDesign6View::OnMycashaccount)
	ON_COMMAND(ID_VIEWBILL_BANKOFCHINAACCOUNT, &CCurriculumDesign6View::OnBankofchinaaccount)
	ON_COMMAND(ID_VIEWBILL_ICBCACCOUNT, &CCurriculumDesign6View::OnIcbcaccount)
	ON_COMMAND(ID_VIEWBILL_MONTHLYINCOMESTATEMENT, &CCurriculumDesign6View::OnMonthly_income_statement)
END_MESSAGE_MAP()

// CCurriculumDesign6View construction/destruction

CCurriculumDesign6View::CCurriculumDesign6View()
{
	// TODO: add construction code here

}

CCurriculumDesign6View::~CCurriculumDesign6View()
{
}

BOOL CCurriculumDesign6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCurriculumDesign6View drawing

void CCurriculumDesign6View::OnDraw(CDC* /*pDC*/)
{
	CCurriculumDesign6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCurriculumDesign6View printing


void CCurriculumDesign6View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCurriculumDesign6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCurriculumDesign6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCurriculumDesign6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCurriculumDesign6View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCurriculumDesign6View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCurriculumDesign6View diagnostics

#ifdef _DEBUG
void CCurriculumDesign6View::AssertValid() const
{
	CView::AssertValid();
}

void CCurriculumDesign6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCurriculumDesign6Doc* CCurriculumDesign6View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCurriculumDesign6Doc)));
	return (CCurriculumDesign6Doc*)m_pDocument;
}
#endif //_DEBUG


// CCurriculumDesign6View message handlers


void CCurriculumDesign6View::OnAddconsumptionrecord()
{
	// TODO: Add your command handler code here
	Add_consumption_record m_main;
	m_main.DoModal();
}


void CCurriculumDesign6View::OnAddrevenuerecord()
{
	// TODO: Add your command handler code here
	Add_revenue_record m_main;
	m_main.DoModal();
}


void CCurriculumDesign6View::OnAddtransferrecord()
{
	// TODO: Add your command handler code here
	Add_transfer_record m_main;
	m_main.DoModal();
}


void CCurriculumDesign6View::OnMycashaccount()
{
	// TODO: Add your command handler code here
	My_cash_account m_main;
	m_main.DoModal();
}


void CCurriculumDesign6View::OnBankofchinaaccount()
{
	// TODO: Add your command handler code here
	BankofChinaaccount m_main;
	m_main.DoModal();
}


void CCurriculumDesign6View::OnIcbcaccount()
{
	// TODO: Add your command handler code here
	Icbcaccount m_main;
	m_main.DoModal();
}


void CCurriculumDesign6View::OnMonthly_income_statement()
{
	// TODO: Add your command handler code here
	Monthly_income_statement m_main;
	m_main.DoModal();
}
