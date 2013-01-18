// FileTimeNewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FileTimeNew.h"
#include "FileTimeNewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CFileTimeNewDlg 对话框




CFileTimeNewDlg::CFileTimeNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileTimeNewDlg::IDD, pParent)
	, m_FileName(_T(""))
	, m_strPath(_T(""))
	, m_strVisit(_T(""))
	, m_strWrite(_T(""))
	, m_strCreate(_T(""))
	, m_wTime(0)
	, m_cTime(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileTimeNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT2, m_visit);
	//DDX_Control(pDX, IDC_EDIT3, m_write);
	//DDX_Control(pDX, IDC_EDIT4, m_creation);
	DDX_Control(pDX, IDC_EDIT1, m_path);
	DDX_Control(pDX, IDC_EDIT2, m_visit);
	DDX_Control(pDX, IDC_EDIT3, m_write);
	DDX_Control(pDX, IDC_EDIT4, m_create);
}

BEGIN_MESSAGE_MAP(CFileTimeNewDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CFileTimeNewDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CFileTimeNewDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_OPEN, &CFileTimeNewDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_SAVE, &CFileTimeNewDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_README, &CFileTimeNewDlg::OnBnClickedReadme)
END_MESSAGE_MAP()


// CFileTimeNewDlg 消息处理程序

BOOL CFileTimeNewDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFileTimeNewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileTimeNewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CFileTimeNewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFileTimeNewDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnOK();
}

void CFileTimeNewDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnCancel();
}

void CFileTimeNewDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	DestroyWindow();
	CDialog::OnClose();
}

void CFileTimeNewDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	PostQuitMessage(0);
}

void CFileTimeNewDlg::OnBnClickedOpen()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog   filedlg(true,NULL,NULL,OFN_DONTADDTORECENT,NULL,
		this,NULL);
	if(IDOK==filedlg.DoModal())
	{
		m_FileName=filedlg.GetPathName();
		m_path.SetWindowTextW(m_FileName);
		CFile File(m_FileName,CFile::modeReadWrite);
		CFileStatus FileStruct;
		File.GetStatus(FileStruct);

		//显示创建时间
		m_strCreate.Format(_T("%u-%u-%u %u:%u:%u"),
			FileStruct.m_ctime.GetYear(),
			FileStruct.m_ctime.GetMonth(),
			FileStruct.m_ctime.GetDay(),
			FileStruct.m_ctime.GetHour(),
			FileStruct.m_ctime.GetMinute(),
			FileStruct.m_ctime.GetSecond());
		m_create.SetWindowTextW(m_strCreate);

		//显示修改时间
		m_strWrite.Format(_T("%u-%u-%u %u:%u:%u"),
			FileStruct.m_mtime.GetYear(),
			FileStruct.m_mtime.GetMonth(),
			FileStruct.m_mtime.GetDay(),
			FileStruct.m_mtime.GetHour(),
			FileStruct.m_mtime.GetMinute(),
			FileStruct.m_mtime.GetSecond());
		m_write.SetWindowTextW(m_strWrite);

		//显示访问时间
		m_strVisit.Format(_T("%u-%u-%u %u:%u:%u"),
			FileStruct.m_atime.GetYear(),
			FileStruct.m_atime.GetMonth(),
			FileStruct.m_atime.GetDay(),
			FileStruct.m_atime.GetHour(),
			FileStruct.m_atime.GetMinute(),
			FileStruct.m_atime.GetSecond());
		m_visit.SetWindowTextW(m_strVisit);
		File.Close();
	}

}

void CFileTimeNewDlg::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
	//CFile File(m_FileName,CFile::modeReadWrite);
	CFileStatus FileStruct;
	int year,month,day,hour,minute,second;

	//File.Close();
	CFile::GetStatus(m_FileName,FileStruct);

	//文件创建时间修改
	m_create.GetWindowTextW(m_strCreate);
	swscanf(m_strCreate,_T("%u-%u-%u %u:%u:%u"),
		&year,&month,&day,&hour,&minute,&second);
	CTime m_cTime(year,month,day,hour,minute,second);
	FileStruct.m_ctime=m_cTime;

	//文件访问时间修改
	m_visit.GetWindowTextW(m_strVisit);
	swscanf(m_strVisit,_T("%u-%u-%u %u:%u:%u"),
		&year,&month,&day,&hour,&minute,&second);
	CTime m_aTime(year,month,day,hour,minute,second);
	FileStruct.m_atime=m_aTime;

	//文件修改时间修改
	m_write.GetWindowTextW(m_strWrite);
	swscanf(m_strWrite,_T("%u-%u-%u %u:%u:%u"),
		&year,&month,&day,&hour,&minute,&second);
	CTime m_mTime(year,month,day,hour,minute,second);
	FileStruct.m_mtime=m_mTime;

	CFile::SetStatus(m_FileName,FileStruct);
}

void CFileTimeNewDlg::OnBnClickedReadme()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"您输入的时间必须在1970-1-1至2038-1-18之间，否则程序即将崩溃\n"
		L"时间格式为XXXX-XX-XX XX:XX:XX",L"说明",MB_ICONINFORMATION);
}
