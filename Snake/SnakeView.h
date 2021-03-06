#pragma once


// CSnakeView view
class CObjectSnake;


class CSnakeView : public CView
{
	DECLARE_DYNCREATE(CSnakeView)
public:
	CSnakeView();           // protected constructor used by dynamic creation
	virtual ~CSnakeView();
protected:
	

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

};


