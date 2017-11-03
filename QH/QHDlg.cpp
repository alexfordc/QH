// QHDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "QH.h"
#include "QHDlg.h"
#include "afxcmn.h"
#include "MdSpi.h"
#include "TraderSpi.h"

extern CThostFtdcMdSpi* pMdSpi;
extern CQHApp theApp;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CTP(void);

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl test;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, test);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CQHDlg 对话框




CQHDlg::CQHDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQHDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	autodoit = false;
}

void CQHDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HANGQING_RECORD, mCListCtrlHangQin);
	DDX_Control(pDX, IDC_LIST_CHICHANG, mCListCtrlChiChang);
	DDX_Control(pDX, IDC_LIST_TRADER_RECORD, mCListCtrlTraderRecord);

	DDX_Control(pDX, IDC_EDIT_ADD_QH, mCEditAddQH);
	DDX_Control(pDX, IDC_COMBO_YUNSUAN, mCComboBoxYunSuan);
	DDX_Control(pDX, IDC_COMBO_TIAOJIAN, mCComboBoxTiaoJian);
	DDX_Control(pDX, IDC_COMBO_QH_1, mCComboBoxQH1);
	DDX_Control(pDX, IDC_COMBO_QH_2, mCComboBoxQH2);
	DDX_Control(pDX, IDC_EDIT_TIAOJIAN_VALUE, mCEditTiaoJianValue);
	DDX_Control(pDX, IDC_STATIC_QH_1_VALUE, mCStaticQH1V);
	DDX_Control(pDX, IDC_STATIC_QH_2_VALUE, mCStaticQH2V);
	DDX_Control(pDX, IDC_COMBO1_MM, mCComboBox1MM);
	DDX_Control(pDX, IDC_COMBO2_MM, mCComboBox2MM);
	DDX_Control(pDX, IDC_STATIC_QH_RE, mCStaticRE);
	DDX_Control(pDX, IDC_STATIC_FLAG, mCStaticFlag);
	DDX_Control(pDX, IDC_COMBO_M_M_1, mCComboBoxMM1trader);
	DDX_Control(pDX, IDC_COMBO_M_M_2, mCComboBoxMM2trader);
	DDX_Control(pDX, IDC_COMBO_KP1, mCComboBoxKP1);
	DDX_Control(pDX, IDC_COMBO_KP2, mCComboBoxKP2);
	DDX_Control(pDX, IDC_COMBO_NUM_1, mCComboBoxNum1);
	DDX_Control(pDX, IDC_COMBO_NUM_2, mCComboBoxNum2);
	DDX_Control(pDX, IDC_COMBO_QH_TRADER_1, mCComboBoxTraderQH1);
	DDX_Control(pDX, IDC_COMBO_QH_TRADER_2, mCComboBoxTraderQH2);
	DDX_Control(pDX, IDC_STATIC_QH_JIAGE_1, mCStaticTraderJiaGe1);
	DDX_Control(pDX, IDC_STATIC_QH_JIAGE_2, mCStaticTraderJiaGe2);
	DDX_Control(pDX, IDC_CHECK_AUTO, mCButtonIsAutoGo);
	DDX_Control(pDX, IDC_BUTTON_GO, mCButtonTraderGo);
	DDX_Control(pDX, IDC_BUTTON_CANCEL, mCButtonTraderCancel);
	DDX_Control(pDX, IDC_BUTTON_ADD, mCButtonAddHeYue);
	DDX_Control(pDX, IDC_STATIC_MONEY, mCStaticMoney);
	DDX_Control(pDX, IDC_BUTTON_UPDATE, mCButtonUpdate);
	DDX_Control(pDX, IDC_LIST_CJ, mCListCtrlCJ);
	DDX_Control(pDX, IDC_BUTTON_GO1, mCButtonGo1);
	DDX_Control(pDX, IDC_BUTTON_GO3, mCButtonGo3);
	DDX_Control(pDX, IDC_CHECK_CLOCK, mCButtonClock);
}

BEGIN_MESSAGE_MAP(CQHDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CQHDlg::OnBnClickedButtonAdd)
	ON_CBN_SELCHANGE(IDC_COMBO_QH_1, &CQHDlg::OnCbnSelchangeComboQh1)
	ON_CBN_SELCHANGE(IDC_COMBO_QH_2, &CQHDlg::OnCbnSelchangeComboQh2)
	ON_CBN_SELENDOK(IDC_COMBO_QH_1, &CQHDlg::OnCbnSelendokComboQh1)
	ON_CBN_SELCHANGE(IDC_COMBO1_MM, &CQHDlg::OnCbnSelchangeCombo1Mm)
	ON_CBN_SELCHANGE(IDC_COMBO2_MM, &CQHDlg::OnCbnSelchangeCombo2Mm)
	ON_CBN_SELCHANGE(IDC_COMBO_YUNSUAN, &CQHDlg::OnCbnSelchangeComboYunsuan)
	ON_CBN_SELCHANGE(IDC_COMBO_TIAOJIAN, &CQHDlg::OnCbnSelchangeComboTiaojian)
	ON_BN_CLICKED(IDC_BUTTON_GO, &CQHDlg::OnBnClickedButtonGo)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, &CQHDlg::OnBnClickedButtonCancel)
	ON_BN_CLICKED(IDC_CHECK_AUTO, &CQHDlg::OnBnClickedCheckAuto)
	ON_EN_SETFOCUS(IDC_EDIT_TIAOJIAN_VALUE, &CQHDlg::OnEnSetfocusEditTiaojianValue)
	ON_CBN_SETFOCUS(IDC_COMBO_QH_1, &CQHDlg::OnCbnSetfocusComboQh1)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CQHDlg::OnBnClickedButtonUpdate)
	ON_BN_CLICKED(IDC_BUTTON_GO1, &CQHDlg::OnBnClickedButtonGo1)
	ON_BN_CLICKED(IDC_BUTTON_GO3, &CQHDlg::OnBnClickedButtonGo3)
	ON_BN_CLICKED(IDC_CHECK_CLOCK, &CQHDlg::OnBnClickedCheckClock)
END_MESSAGE_MAP()


// CQHDlg 消息处理程序

BOOL CQHDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	mCListCtrlHangQin.InsertColumn(0,_T("合约"),LVCFMT_LEFT, 90,-1);
	mCListCtrlHangQin.InsertColumn(1,_T("买价"),LVCFMT_LEFT, 90,-1);
	mCListCtrlHangQin.InsertColumn(2,_T("买量"),LVCFMT_LEFT, 90,-1);
	mCListCtrlHangQin.InsertColumn(3,_T("卖价"),LVCFMT_LEFT, 90,-1);
	mCListCtrlHangQin.InsertColumn(4,_T("卖量"),LVCFMT_LEFT, 90,-1);
	mCListCtrlHangQin.InsertColumn(5,_T("涨跌"),LVCFMT_LEFT, 90,-1);
	mCListCtrlHangQin.InsertColumn(6,_T("成交"),LVCFMT_LEFT, 90,-1);

	mCListCtrlChiChang.InsertColumn(0,_T("合约"),LVCFMT_LEFT, 70,-1);
	mCListCtrlChiChang.InsertColumn(1,_T("买卖"),LVCFMT_LEFT, 70,-1);
	mCListCtrlChiChang.InsertColumn(2,_T("持仓"),LVCFMT_LEFT, 70,-1);
	mCListCtrlChiChang.InsertColumn(3,_T("均价"),LVCFMT_LEFT, 70,-1);
	mCListCtrlChiChang.InsertColumn(4,_T("保证金"),LVCFMT_LEFT, 70,-1);


	mCListCtrlCJ.InsertColumn(0,_T("ORDER"),LVCFMT_LEFT, 70,-1);
	mCListCtrlCJ.InsertColumn(1,_T("买卖"),LVCFMT_LEFT, 70,-1);
	mCListCtrlCJ.InsertColumn(2,_T("合约"),LVCFMT_LEFT, 70,-1);
	mCListCtrlCJ.InsertColumn(3,_T("数量"),LVCFMT_LEFT, 70,-1);
	mCListCtrlCJ.InsertColumn(4,_T("价格"),LVCFMT_LEFT, 70,-1);

		///报单编号

	///组合开平标志

	///价格
	///数量
	///今成交数量
	///剩余数量
	///请求编号
	///本地报单编号

	mCListCtrlTraderRecord.InsertColumn(0,_T("本地报单编号"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(1,_T("ORDER"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(2,_T("合约"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(3,_T("开平"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(4,_T("价格"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(5,_T("数量"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(6,_T("今成交数量"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(7,_T("剩余数量"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(8,_T("请求编号"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(9,_T("报单号"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(10,_T("报单提交状态"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(11,_T("报单状态"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(12,_T("报单类型"),LVCFMT_LEFT, 70,-1);
	mCListCtrlTraderRecord.InsertColumn(13,_T("买卖"),LVCFMT_LEFT, 70,-1);

	mCComboBoxYunSuan.AddString("-");
	mCComboBoxYunSuan.AddString("+");
	mCComboBoxYunSuan.SetCurSel(0);

	mCComboBoxTiaoJian.AddString("=") ;
	mCComboBoxTiaoJian.AddString(">=") ;
	mCComboBoxTiaoJian.AddString("<=") ;
	mCComboBoxTiaoJian.AddString(">") ;
	mCComboBoxTiaoJian.AddString("<") ;
	mCComboBoxTiaoJian.SetCurSel(0) ;

	mCComboBox1MM.AddString("买");
	mCComboBox1MM.AddString("卖");
	mCComboBox1MM.SetCurSel(0);

	mCComboBox2MM.AddString("买");
	mCComboBox2MM.AddString("卖");
	mCComboBox2MM.SetCurSel(0);

	mCComboBoxMM1trader.AddString("买");
	mCComboBoxMM1trader.AddString("卖");
	mCComboBoxMM1trader.SetCurSel(1);

	mCComboBoxMM2trader.AddString("买");
	mCComboBoxMM2trader.AddString("卖");
	mCComboBoxMM2trader.SetCurSel(1);

	mCComboBoxKP1.AddString("开");
	mCComboBoxKP1.AddString("平");
	mCComboBoxKP1.SetCurSel(1);

	mCComboBoxKP2.AddString("开");
	mCComboBoxKP2.AddString("平");
	mCComboBoxKP2.SetCurSel(1);

	mCComboBoxNum1.AddString("1");
	mCComboBoxNum1.AddString("2");
	mCComboBoxNum1.SetCurSel(0);
	
	mCComboBoxNum2.AddString("1");
	mCComboBoxNum2.AddString("2");
	mCComboBoxNum2.SetCurSel(0);

	mCStaticFlag.ShowWindow(SW_HIDE);
	
	CTP();
	mCButtonAddHeYue.EnableWindow(false);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CQHDlg::Message(CString  str)
{
	AfxMessageBox(str);
}

void CQHDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CQHDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CQHDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CQHDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	char str_data[20]={0,};
	char * id[1];
	
	int len = mCEditAddQH.LineLength();
	mCEditAddQH.GetLine(0,(LPTSTR)str_data, len);

	LVFINDINFO info;
	info.flags = LVFI_PARTIAL|LVFI_STRING;
	info.psz = str_data;

	int nRow = mCListCtrlHangQin.FindItem(&info);
	if(nRow==-1)
	{
		id[0] = str_data;
		((CMdSpi*)pMdSpi)->SubscribeMarketData(id,1);
		mCListCtrlHangQin.InsertItem(0, str_data);//插入行
		mCComboBoxQH1.AddString(str_data);
		mCComboBoxQH2.AddString(str_data);
		mCComboBoxTraderQH1.AddString(str_data);
		mCComboBoxTraderQH2.AddString(str_data);
	}else
	{
		Message("合约不能重复添加！");
	}
	
}


void CQHDlg::RtnTrader(CThostFtdcTradeField *pTrade)
{
	char buf[20];
	int nRow=mCListCtrlCJ.InsertItem(0, pTrade->OrderSysID);//插入行
	
	if(pTrade->Direction == '0')
		mCListCtrlCJ.SetItemText(nRow, 1,"买");//设置数据
	else if(pTrade->Direction == '1')
		mCListCtrlCJ.SetItemText(nRow, 1,"卖" );//设置数据

	mCListCtrlCJ.SetItemText(nRow, 2,pTrade->InstrumentID );//设置数据

	sprintf_s(buf,"%d", pTrade->Volume);
	mCListCtrlCJ.SetItemText(nRow, 3,buf);//设置数据

	sprintf_s(buf,"%.2lf", pTrade->Price);
	mCListCtrlCJ.SetItemText(nRow, 4,buf);//设置数据

}
void CQHDlg::ClearChiChangItem()
{
	
}
void CQHDlg::UpdateChiChangList(CThostFtdcInvestorPositionField *pInvestorPosition)
{
	char buf[20];
	if(pInvestorPosition->InstrumentID==0)
		return;
	
	int nRow = mCListCtrlChiChang.InsertItem(0, pInvestorPosition->InstrumentID );//插入行
	if(pInvestorPosition->PosiDirection == '2')
		mCListCtrlChiChang.SetItemText(nRow, 1,"买" );//设置数据
	if(pInvestorPosition->PosiDirection == '3')
		mCListCtrlChiChang.SetItemText(nRow, 1,"卖" );//设置数据
	
	sprintf_s(buf,"%d", pInvestorPosition->Position);
	mCListCtrlChiChang.SetItemText(nRow, 2,buf );//设置数据
	sprintf_s(buf,"%.2lf", pInvestorPosition->PreSettlementPrice);
	mCListCtrlChiChang.SetItemText(nRow, 3,buf );//设置数据
	
	
}
void CQHDlg::UpdateHangQinList(int i)
{
	char buf[20];
	LVFINDINFO info;
	info.flags = LVFI_PARTIAL|LVFI_STRING;
	info.psz = theApp.mDepthMarketDataField[i].InstrumentID;

	int nRow = mCListCtrlHangQin.FindItem(&info);
	if(nRow == -1)
		nRow = mCListCtrlHangQin.InsertItem(0, theApp.mDepthMarketDataField[i].InstrumentID );//插入行

    sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].BidPrice1);
	mCListCtrlHangQin.SetItemText(nRow, 1,buf );//设置数据
	sprintf_s(buf,"%d", theApp.mDepthMarketDataField[i].BidVolume1);
	mCListCtrlHangQin.SetItemText(nRow, 2, buf);//设置数据
	sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].AskPrice1);
	mCListCtrlHangQin.SetItemText(nRow, 3, buf);//设置数据
	sprintf_s(buf,"%d", theApp.mDepthMarketDataField[i].AskVolume1);
	mCListCtrlHangQin.SetItemText(nRow, 4, buf);//设置数据
	//mCListCtrlHangQin.SetItemText(nRow, 5, theApp.mDepthMarketDataField[i]. .BidVolume1);//设置数据
	//mCListCtrlHangQin.SetItemText(nRow, 6, theApp.mDepthMarketDataField[i].BidVolume1);//设置数据
	CbnSelchangeCombo1Mm();
	CbnSelchangeCombo2Mm();
	CbnSelchangeCombo1TraderMm();
	CbnSelchangeCombo2TraderMm();
	calculate();
	if(result() && autodoit)
	{
		//下单；
		GoTrader();
		autodoit = false;
		mCButtonIsAutoGo.SetCheck(0);
		SetEnGUI(true);
	}
}
bool CQHDlg::result()
{
	char buf[20];
	mCEditTiaoJianValue.GetWindowText(buf,20);
	double val = atof(buf);
	int index = mCComboBoxTiaoJian.GetCurSel();
	bool flag =false;
	if(index == 0)//=
	{
		if(mResult==val)
			flag = true;
	}
	else if(index == 1)//>=
	{
		if(mResult>=val)
			flag = true;
	}
	else if(index == 2)//<=
	{
		if(mResult<=val)
			flag = true;
	}
	else if(index == 3)//>
	{
		if(mResult>val)
			flag = true;
	}
	else if(index == 4)//<
	{
		if(mResult<val)
			flag = true;
	}

	if(flag)
		mCStaticFlag.ShowWindow(SW_SHOW);
	else 
		mCStaticFlag.ShowWindow(SW_HIDE);

	return flag;
	//mCStaticRE.SetWindowText((LPCTSTR)tmp);

}
void CQHDlg::OnCbnSelchangeComboQh1()
{
	mCComboBoxTraderQH1.SetCurSel(mCComboBoxQH1.GetCurSel());
	CbnSelchangeCombo1Mm();
	calculate();
	
}

void CQHDlg::OnCbnSelchangeComboQh2()
{
	// TODO: 在此添加控件通知处理程序代码
	mCComboBoxTraderQH2.SetCurSel(mCComboBoxQH2.GetCurSel());
	CbnSelchangeCombo2Mm();
	calculate();

}

void CQHDlg::OnCbnSelendokComboQh1()
{
	// TODO: 在此添加控件通知处理程序代码
	
}

void CQHDlg::OnCbnSelchangeCombo1Mm()
{
	if(mCComboBox1MM.GetCurSel()==0)
		mCComboBoxMM1trader.SetCurSel(1);
	else if(mCComboBox1MM.GetCurSel()==1)
		mCComboBoxMM1trader.SetCurSel(0);
	
	CbnSelchangeCombo1Mm();
	calculate();
}

void CQHDlg::OnCbnSelchangeCombo2Mm()
{
	if(mCComboBox2MM.GetCurSel()==0)
		mCComboBoxMM2trader.SetCurSel(1);
	else if(mCComboBox2MM.GetCurSel()==1)
		mCComboBoxMM2trader.SetCurSel(0);

	CbnSelchangeCombo2Mm();
	calculate();
}
void CQHDlg::CbnSelchangeCombo1Mm()
{
	// TODO: 在此添加控件通知处理程序代码
	char tmp[31];
	char buf[20];
	int index = mCComboBoxQH1.GetCurSel();
	mCComboBoxQH1.GetLBText(index,tmp);
	//mCComboBoxQH1.GetWindowText((LPTSTR)tmp,31);
	for(int i=0;i<100;i++)
	{
		if(0==strcmp(tmp ,theApp.mDepthMarketDataField[i].InstrumentID))
		{
			if(mCComboBox1MM.GetCurSel()==1)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].AskPrice1);
				mCStaticQH1V.SetWindowText((LPCTSTR)buf);
			}
			else if(mCComboBox1MM.GetCurSel()==0)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].BidPrice1);
				mCStaticQH1V.SetWindowText((LPCTSTR)buf);
			}
			break;
		}
	}
}

void CQHDlg::CbnSelchangeCombo2Mm()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	char tmp[31];
	char buf[20];
	int index = mCComboBoxQH2.GetCurSel();
	mCComboBoxQH2.GetLBText(index,tmp);
	//mCComboBoxQH1.GetWindowText((LPTSTR)tmp,31);
	for(int i=0;i<100;i++)
	{
		if(0==strcmp(tmp ,theApp.mDepthMarketDataField[i].InstrumentID))
		{
			if(mCComboBox2MM.GetCurSel()==1)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].AskPrice1);
				mCStaticQH2V.SetWindowText((LPCTSTR)buf);
			}
			else if(mCComboBox2MM.GetCurSel()==0)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].BidPrice1);
				mCStaticQH2V.SetWindowText((LPCTSTR)buf);
			}
			break;
		}
	}

}

void CQHDlg::CbnSelchangeCombo1TraderMm()
{
	// TODO: 在此添加控件通知处理程序代码
	char tmp[31];
	char buf[20];
	int index = mCComboBoxTraderQH1.GetCurSel();
	mCComboBoxTraderQH1.GetLBText(index,tmp);
	//mCComboBoxQH1.GetWindowText((LPTSTR)tmp,31);
	for(int i=0;i<100;i++)
	{
		if(0==strcmp(tmp ,theApp.mDepthMarketDataField[i].InstrumentID))
		{
			if(mCComboBoxMM1trader.GetCurSel()==0)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].AskPrice1);
				mCStaticTraderJiaGe1.SetWindowText((LPCTSTR)buf);
				mCComboBoxKP1.SetCurSel(0);
			}
			else if(mCComboBoxMM1trader.GetCurSel()==1)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].BidPrice1);
				mCStaticTraderJiaGe1.SetWindowText((LPCTSTR)buf);
				mCComboBoxKP1.SetCurSel(1);
			}
			break;
		}
	}
}


void CQHDlg::CbnSelchangeCombo2TraderMm()
{
	// TODO: 在此添加控件通知处理程序代码
	char tmp[31];
	char buf[20];
	int index = mCComboBoxTraderQH2.GetCurSel();
	mCComboBoxTraderQH2.GetLBText(index,tmp);
	//mCComboBoxQH1.GetWindowText((LPTSTR)tmp,31);
	for(int i=0;i<100;i++)
	{
		if(0==strcmp(tmp ,theApp.mDepthMarketDataField[i].InstrumentID))
		{
			if(mCComboBoxMM2trader.GetCurSel()==0)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].AskPrice1);
				mCStaticTraderJiaGe2.SetWindowText((LPCTSTR)buf);
				mCComboBoxKP2.SetCurSel(0);
			}
			else if(mCComboBoxMM2trader.GetCurSel()==1)
			{
				sprintf_s(buf,"%.2lf", theApp.mDepthMarketDataField[i].BidPrice1);
				mCStaticTraderJiaGe2.SetWindowText((LPCTSTR)buf);
				mCComboBoxKP2.SetCurSel(1);
			}
			break;
		}
	}
}


void CQHDlg::OnCbnSelchangeComboYunsuan()
{
	// TODO: 在此添加控件通知处理程序代码
	calculate();

}

void CQHDlg::OnCbnSelchangeComboTiaojian()
{
	// TODO: 在此添加控件通知处理程序代码
	calculate();
}

void CQHDlg::calculate()
{
	char buf[20];
	char buf2[20];
	mCStaticQH1V.GetWindowText(buf,20);
	mCStaticQH2V.GetWindowText(buf2,20);

	int index = mCComboBoxYunSuan.GetCurSel();
	
	if(index == 0)//-
	{
		mResult = atof(buf) - atof(buf2);
	}
	else if(index == 1)//+
	{
		mResult = atof(buf) - atof(buf2);
	}
	char tmp[20];
	sprintf_s(tmp,"%.2lf", mResult);
	mCStaticRE.SetWindowText((LPCTSTR)tmp);
}

void CQHDlg::OnBnClickedButtonGo()
{
	// TODO: 在此添加控件通知处理程序代码
	GoTrader();
}
void CQHDlg::GoTrader()
{
	GoTrader1();
	GoTrader2();
}
void CQHDlg::GoTrader1()
{
	TThostFtdcInstrumentIDType Instrument_ID;
	TThostFtdcDirectionType Direction;
	TThostFtdcOffsetFlagType MarketState;
	TThostFtdcPriceType price;
	int vol;

	
	mCComboBoxTraderQH1.GetLBText(mCComboBoxTraderQH1.GetCurSel(),Instrument_ID);

	if(mCComboBoxMM1trader.GetCurSel()==0)
		Direction = THOST_FTDC_D_Buy;
	else if(mCComboBoxMM1trader.GetCurSel()==1)
		Direction = THOST_FTDC_D_Sell;

	if(mCComboBoxKP1.GetCurSel()==0)//kai
		MarketState = THOST_FTDC_OF_Open;
	else if(mCComboBoxKP1.GetCurSel()==1)//pin
		MarketState = THOST_FTDC_OF_Close;

	char buf[20];
	mCStaticTraderJiaGe1.GetWindowText(buf,20);
	price = atof(buf);

	mCComboBoxNum1.GetLBText(mCComboBoxNum1.GetCurSel(),buf);
	vol = atoi(buf);

	pUserSpi->ReqOrderInsert(Instrument_ID,Direction,MarketState,price,vol);
}
void CQHDlg::GoTrader2()
{
	////////////下第二个单
	TThostFtdcInstrumentIDType Instrument_ID;
	TThostFtdcDirectionType Direction;
	TThostFtdcOffsetFlagType MarketState;
	TThostFtdcPriceType price;
	int vol;
	char buf[20];

	mCComboBoxTraderQH2.GetLBText(mCComboBoxTraderQH2.GetCurSel(),Instrument_ID);

	if(mCComboBoxMM2trader.GetCurSel()==0)
		Direction = THOST_FTDC_D_Buy;
	else if(mCComboBoxMM2trader.GetCurSel()==1)
		Direction = THOST_FTDC_D_Sell;

	if(mCComboBoxKP2.GetCurSel()==0)//kai
		MarketState = THOST_FTDC_OF_Open;
	else if(mCComboBoxKP2.GetCurSel()==1)//pin
		MarketState = THOST_FTDC_OF_Close;

	mCStaticTraderJiaGe2.GetWindowText(buf,20);
	price = atof(buf);

	mCComboBoxNum2.GetLBText(mCComboBoxNum1.GetCurSel(),buf);
	vol = atoi(buf);

	pUserSpi->ReqOrderInsert(Instrument_ID,Direction,MarketState,price,vol);
}

void CQHDlg::SetMoney(char* str)
{
	mCStaticMoney.SetWindowText(str);
}

void CQHDlg::RtnOrder(CThostFtdcOrderField *pOrder)
{
	char buf[20];
	LVFINDINFO info;
	info.flags = LVFI_PARTIAL|LVFI_STRING;
	info.psz = pOrder->OrderLocalID;

	///本地报单编号
	int nRow = mCListCtrlTraderRecord.FindItem(&info);
	if(nRow == -1)
		nRow = mCListCtrlTraderRecord.InsertItem(0, pOrder->OrderLocalID);//插入行

	///Order
	
	mCListCtrlTraderRecord.SetItemText(nRow, 1,pOrder->OrderRef );//设置数据
	///合约
	mCListCtrlTraderRecord.SetItemText(nRow, 2,pOrder->InstrumentID );//设置数据
	///组合开平标志
	if(pOrder->CombOffsetFlag[0]=='0')
		mCListCtrlTraderRecord.SetItemText(nRow, 3,"开" );//设置数据
	else if(pOrder->CombOffsetFlag[0]=='1')
		mCListCtrlTraderRecord.SetItemText(nRow, 3,"平" );//设置数据
	///价格
	sprintf_s(buf,"%.2lf", pOrder->LimitPrice);
	mCListCtrlTraderRecord.SetItemText(nRow, 4,buf );//设置数据
	///数量
	sprintf_s(buf,"%d", pOrder->VolumeTotalOriginal);
	mCListCtrlTraderRecord.SetItemText(nRow, 5,buf );//设置数据
	///今成交数量
	sprintf_s(buf,"%d", pOrder->VolumeTraded);
	mCListCtrlTraderRecord.SetItemText(nRow, 6,buf );//设置数据
	///剩余数量
	sprintf_s(buf,"%d", pOrder->VolumeTotal);
	mCListCtrlTraderRecord.SetItemText(nRow, 7,buf );//设置数据
	///请求编号
	sprintf_s(buf,"%d", pOrder->RequestID);
	mCListCtrlTraderRecord.SetItemText(nRow, 8,buf );//设置数据
	///报单编号
	mCListCtrlTraderRecord.SetItemText(nRow, 9,pOrder->OrderSysID  );//设置数据
	
	///报单提交状态
	if(pOrder->OrderSubmitStatus == THOST_FTDC_OSS_InsertSubmitted)
		mCListCtrlTraderRecord.SetItemText(nRow, 10,"已经提交" );//设置数据
	else if(pOrder->OrderSubmitStatus == THOST_FTDC_OSS_CancelSubmitted)
		mCListCtrlTraderRecord.SetItemText(nRow, 10,"撤单已经提交" );//设置数据
	else if(pOrder->OrderSubmitStatus == THOST_FTDC_OSS_ModifySubmitted)
		mCListCtrlTraderRecord.SetItemText(nRow, 10,"修改已经提交" );//设置数据
	else if(pOrder->OrderSubmitStatus == THOST_FTDC_OSS_Accepted)
		mCListCtrlTraderRecord.SetItemText(nRow, 10,"已经接受" );//设置数据
	else if(pOrder->OrderSubmitStatus == THOST_FTDC_OSS_InsertRejected)
		mCListCtrlTraderRecord.SetItemText(nRow, 10,"报单已经被拒绝" );//设置数据
	else if(pOrder->OrderSubmitStatus == THOST_FTDC_OSS_CancelRejected)
		mCListCtrlTraderRecord.SetItemText(nRow, 10,"撤单已经被拒绝" );//设置数据
	else if(pOrder->OrderSubmitStatus == THOST_FTDC_OSS_ModifyRejected)
		mCListCtrlTraderRecord.SetItemText(nRow, 10,"改单已经被拒绝" );//设置数据
	
	///报单状态
	if(pOrder->OrderStatus == THOST_FTDC_OST_AllTraded)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"全部成交" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_PartTradedQueueing)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"部分成交还在队列中" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_PartTradedNotQueueing)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"部分成交不在队列中" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_NoTradeQueueing)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"未成交还在队列中" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_NoTradeNotQueueing)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"未成交不在队列中" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_Canceled)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"撤单" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_Unknown)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"未知" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_NotTouched)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"尚未触发" );//设置数据
	else if(pOrder->OrderStatus == THOST_FTDC_OST_Touched)
		mCListCtrlTraderRecord.SetItemText(nRow, 11,"已触发" );//设置数据

	///报单类型
	if(pOrder->OrderType == THOST_FTDC_ORDT_Normal)
		mCListCtrlTraderRecord.SetItemText(nRow, 12,"正常" );//设置数据
	else if(pOrder->OrderType == THOST_FTDC_ORDT_DeriveFromQuote)
		mCListCtrlTraderRecord.SetItemText(nRow, 12,"报价衍生" );//设置数据
	else if(pOrder->OrderType == THOST_FTDC_ORDT_DeriveFromCombination)
		mCListCtrlTraderRecord.SetItemText(nRow, 12,"组合衍生" );//设置数据
	else if(pOrder->OrderType == THOST_FTDC_ORDT_Combination)
		mCListCtrlTraderRecord.SetItemText(nRow, 12,"组合报单" );//设置数据
	else if(pOrder->OrderType == THOST_FTDC_ORDT_ConditionalOrder)
		mCListCtrlTraderRecord.SetItemText(nRow, 12,"条件单" );//设置数据
	else if(pOrder->OrderType == THOST_FTDC_ORDT_Swap)
		mCListCtrlTraderRecord.SetItemText(nRow, 12,"互换单" );//设置数据

	if(pOrder->Direction ==THOST_FTDC_D_Buy)
		mCListCtrlTraderRecord.SetItemText(nRow, 13,"买" );//设置数据
	else if(pOrder->Direction ==THOST_FTDC_D_Sell)
		mCListCtrlTraderRecord.SetItemText(nRow, 13,"卖" );//设置数据

}
void CQHDlg::OnBnClickedButtonCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	TThostFtdcOrderSysIDType OrderSysID;
	for(int i=0; i<mCListCtrlTraderRecord.GetItemCount(); i++ )
    {
		CString str1;
		str1=mCListCtrlTraderRecord.GetItemText(i,11);
		if(str1!="全部成交" && str1!="撤单" && str1!="部分成交不在队列中" )
		{
			
			CString str;
			str=mCListCtrlTraderRecord.GetItemText(i,9);
			char *p =(LPSTR)(LPCTSTR)str;
			memset(OrderSysID,0,21);
			memcpy(OrderSysID,p,strlen(p));

			str=mCListCtrlTraderRecord.GetItemText(i,1);
			p =(LPSTR)(LPCTSTR)str;

			CString str1=mCListCtrlTraderRecord.GetItemText(i,2);
			
			
			pUserSpi->ReqOrderAction(OrderSysID,atoi(p),(LPSTR)(LPCTSTR)str1);
		}
    }	

}

void CQHDlg::OnBnClickedCheckAuto()
{
	// TODO: 在此添加控件通知处理程序代码
	if (mCButtonIsAutoGo.GetCheck()==0)
	{
		autodoit = false;
		SetEnGUI(!autodoit);
	}
	if (mCButtonIsAutoGo.GetCheck()==1)
	{
		autodoit = true;
		SetEnGUI(!autodoit);
	}
}


void CQHDlg::SetEnGUI(bool b)
{
	mCComboBoxYunSuan.EnableWindow(b) ;
	mCComboBoxTiaoJian.EnableWindow(b);
	mCComboBoxQH1.EnableWindow(b);
	mCComboBoxQH2.EnableWindow(b);
	mCComboBox1MM.EnableWindow(b);
	mCComboBox2MM.EnableWindow(b);
	mCComboBoxMM1trader.EnableWindow(b);
	mCComboBoxMM2trader.EnableWindow(b);
	mCComboBoxKP1.EnableWindow(b);
	mCComboBoxKP2.EnableWindow(b);
	mCComboBoxNum1.EnableWindow(b);
	mCComboBoxNum2.EnableWindow(b);
	mCComboBoxTraderQH1.EnableWindow(b);
	mCComboBoxTraderQH2.EnableWindow(b);
	
	mCEditTiaoJianValue.EnableWindow(b);
	CButton mCButtonIsAutoGo;
	
}

void CQHDlg::OnEnSetfocusEditTiaojianValue()
{
	
}

void CQHDlg::OnCbnSetfocusComboQh1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CQHDlg::OnBnClickedButtonUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
	
	mCListCtrlChiChang.DeleteAllItems();
	pUserSpi->ReqQryInvestorPosition();

	pUserSpi->ReqQryTradingAccount();


}

void CQHDlg::OnBnClickedButtonGo1()
{
	// TODO: 在此添加控件通知处理程序代码
	GoTrader1();
	
}

void CQHDlg::OnBnClickedButtonGo3()
{
	// TODO: 在此添加控件通知处理程序代码
	GoTrader2();
}

void CQHDlg::OnBnClickedCheckClock()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	if(mCButtonIsAutoGo.GetCheck()==1)
		return;
	if (mCButtonClock.GetCheck()==0)
	{
		SetEnGUI(true);
		EnableTrader(true);
		mCButtonClock.EnableWindow(true);
	}
	if (mCButtonClock.GetCheck()==1)
	{
		SetEnGUI(false);
		EnableTrader(false);
		mCButtonClock.EnableWindow(true);
	}
}
