
// xialiangwei10View.h : interface of the Cxialiangwei10View class
//

#pragma once


class Cxialiangwei10View : public CView
{
protected: // create from serialization only
	Cxialiangwei10View();
	DECLARE_DYNCREATE(Cxialiangwei10View)

// Attributes
public:
	Cxialiangwei10Doc* GetDocument() const;

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
	virtual ~Cxialiangwei10View();
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
	afx_msg void OnCalculation();
};

#ifndef _DEBUG  // debug version in xialiangwei10View.cpp
inline Cxialiangwei10Doc* Cxialiangwei10View::GetDocument() const
   { return reinterpret_cast<Cxialiangwei10Doc*>(m_pDocument); }
#endif

