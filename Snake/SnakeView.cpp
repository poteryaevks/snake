// CSnakeView.cpp : implementation file
//

#include "stdafx.h"
#include "Snake.h"
#include "SnakeView.h"
#include "CObjectSnake.h"


// CSnakeView

IMPLEMENT_DYNCREATE(CSnakeView, CView)

CSnakeView::CSnakeView()
{

	
}

CSnakeView::~CSnakeView()
{
	
}



BEGIN_MESSAGE_MAP(CSnakeView, CView)
	
END_MESSAGE_MAP()


// CSnakeView drawing
void CSnakeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CSnakeView diagnostics

#ifdef _DEBUG
void CSnakeView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSnakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSnakeView message handlers


void CSnakeView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}


BOOL CSnakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CView::PreCreateWindow(cs);
}




