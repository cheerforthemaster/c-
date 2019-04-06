
// xlwei9View.h : interface of the Cxlwei9View class
//

#pragma once


class Cxlwei9View : public CView
{
protected: // create from serialization only
	Cxlwei9View();
	DECLARE_DYNCREATE(Cxlwei9View)

// Attributes
public:
	Cxlwei9Doc* GetDocument() const;

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
	virtual ~Cxlwei9View();
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
	afx_msg void OnGetinformation();
	afx_msg void OnFileNew();
	afx_msg void OnReadinformation();
	afx_msg void OnChangeinformation();
	afx_msg void OnGetinformationLocation();
};

#ifndef _DEBUG  // debug version in xlwei9View.cpp
inline Cxlwei9Doc* Cxlwei9View::GetDocument() const
   { return reinterpret_cast<Cxlwei9Doc*>(m_pDocument); }
#endif

