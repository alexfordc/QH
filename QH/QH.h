// QH.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#include "QHDlg.h"		// ������


// CQHApp:
// �йش����ʵ�֣������ QH.cpp
//

class CQHApp : public CWinApp
{
public:
	CQHDlg *mdlg;
	CQHApp();

	void EnableGUI(){mdlg->EnableHangQin();};
	void EnableTrader(){mdlg->EnableTrader();};
	void SetMoney(char* c){mdlg->SetMoney(c); };
	void ClearChiChangItem(){mdlg->ClearChiChangItem();};
	void RtnTrader(CThostFtdcTradeField *pTrade){mdlg->RtnTrader(pTrade);};

// ��д
public:
	virtual BOOL InitInstance();
	void Message(CString  str);
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition);
	void RtnOrder(CThostFtdcOrderField *pOrder);

// ʵ��

	DECLARE_MESSAGE_MAP()
public:
	CThostFtdcDepthMarketDataField mDepthMarketDataField[100];
};

extern CQHApp theApp;