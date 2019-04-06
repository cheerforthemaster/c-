
// CurriculumDesign6View.h : interface of the CCurriculumDesign6View class
//

#pragma once


class CCurriculumDesign6View : public CView
{
protected: // create from serialization only
	CCurriculumDesign6View();
	DECLARE_DYNCREATE(CCurriculumDesign6View)

// Attributes
public:
	CCurriculumDesign6Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CCurriculumDesign6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAddconsumptionrecord();
	afx_msg void OnAddrevenuerecord();
	afx_msg void OnAddtransferrecord();
	afx_msg void OnMycashaccount();
	afx_msg void OnBankofchinaaccount();
	afx_msg void OnIcbcaccount();
	afx_msg void OnMonthly_income_statement();
};

#ifndef _DEBUG  // debug version in CurriculumDesign6View.cpp
inline CCurriculumDesign6Doc* CCurriculumDesign6View::GetDocument() const
   { return reinterpret_cast<CCurriculumDesign6Doc*>(m_pDocument); }
#endif

