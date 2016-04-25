// QH.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "QH.h"
#include "QHDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQHApp

BEGIN_MESSAGE_MAP(CQHApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CQHApp 构造

CQHApp::CQHApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
	for(int i=0;i<100;i++)
	{
		memset(mDepthMarketDataField[i].InstrumentID,0,sizeof(TThostFtdcInstrumentIDType));
	}
}


// 唯一的一个 CQHApp 对象

CQHApp theApp;


// CQHApp 初始化

BOOL CQHApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CQHDlg dlg;
	m_pMainWnd = &dlg;
	mdlg = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	
	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

void CQHApp::Message(CString  str)
{
	mdlg->Message(str);
}
void CQHApp::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition)
{
	mdlg->UpdateChiChangList(pInvestorPosition);
}
void CQHApp::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	TThostFtdcInstrumentIDType nullId;
	memset(nullId,0,sizeof(TThostFtdcInstrumentIDType));
	int i=0;
	for(i=0;i<100;i++)
	{
		if(0==strcmp(pDepthMarketData->InstrumentID ,mDepthMarketDataField[i].InstrumentID) || 
			0==strcmp(nullId ,mDepthMarketDataField[i].InstrumentID))
		{
			mDepthMarketDataField[i] = *pDepthMarketData;
			break;
		}
	}
	mdlg->UpdateHangQinList(i);

}

void CQHApp::RtnOrder(CThostFtdcOrderField *pOrder)
{
	mdlg->RtnOrder(pOrder);
}