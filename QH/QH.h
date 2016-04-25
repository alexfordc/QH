// QH.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

#include "QHDlg.h"		// 主符号


// CQHApp:
// 有关此类的实现，请参阅 QH.cpp
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

// 重写
public:
	virtual BOOL InitInstance();
	void Message(CString  str);
	void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
	void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition);
	void RtnOrder(CThostFtdcOrderField *pOrder);

// 实现

	DECLARE_MESSAGE_MAP()
public:
	CThostFtdcDepthMarketDataField mDepthMarketDataField[100];
};

extern CQHApp theApp;