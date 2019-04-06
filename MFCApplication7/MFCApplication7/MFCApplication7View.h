
// MFCApplication7View.h : interface of the CMFCApplication7View class
//

#pragma once


class CMFCApplication7View : public CView
{
protected: // create from serialization only
	CMFCApplication7View();
	DECLARE_DYNCREATE(CMFCApplication7View)

// Attributes
public:
	CMFCApplication7Doc* GetDocument() const;

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
	virtual ~CMFCApplication7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCApplication7View.cpp
inline CMFCApplication7Doc* CMFCApplication7View::GetDocument() const
   { return reinterpret_cast<CMFCApplication7Doc*>(m_pDocument); }
#endif

