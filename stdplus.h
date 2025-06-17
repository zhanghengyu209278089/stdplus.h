#ifndef STD_PLUS_H_INCLUDE_48261883901703533062691882888416
#define STD_PLUS_H_INCLUDE_48261883901703533062691882888416
#define ALL_INCLUDE_STDPLUS_H
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
//stdplus.h include
/*
	Name: stdplus.h
	Copyright: null
	Author: HenryZhang
	Date: 30/05/25
	Description: This is an enhanced version of the STD.
*/

/*
- stdplus.h
	- defines
		- STD_PLUS_H_INCLUDE_48261883901703533062691882888416
		- ALL_INCLUDE_STDPLUS_H
	- namespace
		- std
		- stdplus
		- complex_auto_casting
	- defaut-tool
		- complex_auto_casting
			- to solve the casting problem of std::complex<_Tp>
			- define NDEF_CAC to delete
	- class
		- BWGraph
	- functions
		- menu
		- vbs-socket
			- ...
		- curl-tool
			-  get_dict
*/
namespace stdplus{
	/*
	This is a free library.
	It made by Mr Henry Zhang.
	*/
	//the matrix class
	void set_color(int x){
		HANDLE consolehwnd;
		consolehwnd=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd,x);
		return;
	}
	//the function to show menu
	template <typename T>
	int menu(vector<T> box){
		int boxsize=box.size();
		int index=0;
		char ch;
		while (1){
			system("cls");
			cout<<"按上下键选择，按回车确定。"<<endl;
			cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
			for (int i=0;i<boxsize;i++){
				if(i==index) set_color(0xF0);
				else set_color(0x0F);
				cout<<box[i]<<'\n';
			}
			set_color(0x0F);
			cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
			ch=getch();
			if(ch==72||ch==80||ch==27||ch==13){
				if(ch==27) {
					break;
				}
				if(ch==72){
					index=max(0,index-1);
				}
				if(ch==80){
					index=min(boxsize-1,index+1);
				}
				if(ch==13) {
					return index;
				}
			}
			Sleep(10);
		}
		return -1;
	}
	//maths function good then std libraries
	template <typename _Tp>
	_Tp fast_pow(_Tp x,_Tp y,_Tp _mod){
		if(y==0) return 1;
		if(y%2==1) return x*fast_pow(x,y-1,_mod)%_mod;
		else {
			_Tp tmp=fast_pow(x,y/2,_mod);
			return tmp*tmp%_mod;
		}
	}
	bool Isprime(long long x){
		if(x<2) return false;
		for (long long i=2;i*i<=x;i++)
			if(x%i==0) return false;
		return true;
	}
	//easy graphics library
	#define COLORSTRING(c) FOREGROUND_##c
	
	void colorsqaure(int x){
		HANDLE consolehwnd;
		consolehwnd=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(consolehwnd,x);
		cout<<"█";
		SetConsoleTextAttribute(consolehwnd,0x07);
		return;
	}
	void putpaper(bool **&arr,int n,int m){
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 1;                  
		cfi.dwFontSize.Y = 1;         
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		std::wcscpy(cfi.FaceName, L"Consolas"); 
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		system("mode con cols=5000 lines=5000");
		arr=new bool*[n];
		for (int i=0;i<n;i++)
			arr[i]=new bool[m];
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				arr[i][j]=0;
		return;
	}
	void line(bool **arr,int x1,int y1,int x2,int y2){
		if(x1>x2) {
			swap(x1,x2);
			swap(y1,y2);
		}
		if(x1==x2){
			for (int i=min(y1,y2);i<=max(y1,y2);i++)
				arr[x1][i]=1;
			return;
		}
		double ptr;
		if(y1-y2==0) ptr=0;
		else ptr=(y1-y2)*1.0/(x2-x1);
		for (int i=x1;i<=x2;i++){
			int j=y1+ptr*(x1-i);
			arr[i][j]=1;
		}
		return;
	}
	void paint(int n,int m,bool **arr){
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if(arr[i][j]) colorsqaure(COLORSTRING(GREEN));
				else cout<<' ';
			}
			cout<<'\n';
		}
		return;
	}
	using BWGraph=bool**; 
	bool mandelbrot_set(double x,double y,int max_iter=100){
		complex<double> c(x,y);
		complex<double> z=0;
		for (int i=1;i<=max_iter;i++){
			z=pow(z,2)+c/2.0;
			if(abs(z)>2) return false;
		}
		return true;
	}
	void show_mandelbrot_set(){
		bool a[1005][1005];
		memset(a,0,sizeof(a));
		for (int i=1;i<=1000;i++){
			for (int j=1;j<=1000;j++)
				a[i][j]=mandelbrot_set((i-500)/100.0,(j-500)/100.0);
		}
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 1;                   // Width of each character in the font
		cfi.dwFontSize.Y = 1;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
		system("mode con cols=10000 lines=5000");
		for (int i=1;i<=1000;i++){
			for (int j=1;j<=1000;j++){
				if(a[i][j]) colorsqaure(COLORSTRING(GREEN));
				else cout<<' ';
			} 
			cout<<'\n';
		}
	}
	//this library have meta-program template-meta-function
	template <int A,int B>
	struct meta_gcd{
		static int const value=meta_gcd<B,A%B>::value;	
	};
	template <int A>
	struct meta_gcd<A,0>{
		static int const value=A;
	};
	//meta gcd function
	template <int A,int B>
	struct meta_lcm{
		static int const value=A*B/meta_gcd<A,B>::value;
	};
	template <int N>
	struct meta_fib{
		static int const value=meta_fib<N-1>::value+meta_fib<N-2>::value;
	};
	template <>
	struct meta_fib<1>{
		static int const value=1;
	};
	template <>
	struct meta_fib<2>{
		static int const value=1;
	};
	//meta fibroncii function
	typedef void(*Meta_Loop_Ptr)(int);
	template <Meta_Loop_Ptr some_statement,int A,int B,int loop_i=A>
	struct meta_loop{
		void exec(){
			some_statement(loop_i);
			meta_loop<some_statement,A,B,loop_i+1> tmp;
			tmp.exec();
		}
	};
	template <Meta_Loop_Ptr some_statement,int A,int B>
	struct meta_loop<some_statement,A,B,B>{
		void exec(){
			some_statement(B);
		}
	};
	//meta loop
	void open_html_aux(string html_code){//
		ofstream html_pip("tmp_html_code.html");
		html_pip<<html_code;
		html_pip.close();
		return;
	}
	///this is the HTML linking creater
	#define OPEN_HTML(html_code) open_html_aux(html_code);system("start tmp_html_code.html")//this define can create and open html codes
	class m_any_t{//my any type(it likes boost::any)
		private:
			void* m_val;
		public:
			template <typename _Tp>
			void set_type(){
				m_val=nullptr;
				m_val=new _Tp;
				return;
			}
			template <typename _Tp>
			_Tp& get(){
				return *(_Tp*)m_val;
			}
			template <typename _Tp>
			void set(_Tp n_val){
				*(_Tp*)m_val=n_val;
				return;
			}
	};
	//the function to wait for a long time
	void wait(int t_s){//t_s is the time to wait
		long long stop=t_s+time(0);
		while (time(0)!=stop){
		}
		return;
	}
	//system("cls")
	void _cls(){
		system("cls");
		return;
	}
	//system("shutdown -s -f -t 0")
	void _shutdown(){
		system("shutdown -s -f -t 0");
		return;
	}
	//the function to speak text
	void speak(string Text){
		ofstream fout("speak_text.vbs");
		fout<<"CreateObject(\"sapi.spvoice\").Speak \""<<Text<<"\"";
		fout.close();
		system("speak_text.vbs");
		return;
	}
	vector<string> get_dict(string word){
		int ok=system(("curl -# https://www.qifanda.com/dict/"+word+".html | find \"<p>1.\">my_search.txt").c_str());
		if(ok!=0) return vector<string>{};
		system("cls");
		vector<string> result;
		string tmp;
		ifstream fin("my_search.txt");
		while(getline(fin,tmp)){
			result.push_back(tmp);
		}
		for (int i=0;i<result.size();i++){
			if(result[i].find("<p>1.")!=string::npos) result[i].erase(result[i].find("<p>"),5);
			if(result[i].find("</p>")!=string::npos) result[i].erase(result[i].find("</p>"),4);
		}
		return result;
	}
	string InputBox(string output){
		ofstream fout("tmp.vbs");
		fout<<"Dim fso, file\nSet fso = CreateObject(\"Scripting.FileSystemObject\")\nSet file = fso.CreateTextFile(\"tmp.txt\", True)\nmsg=InputBox(\""<<output<<"\",\"InputBox\")\nfile.WriteLine(msg)\nfile.Close\nSet file = Nothing\nSet fso = Nothing\n";
		fout.close();
		system("tmp.vbs");
		ifstream fin("tmp.txt");
		string res;
		string tmp;
		while(getline(fin,tmp)){
			res+=tmp+"\n";
		}
		return res;
	}
	//solve the casting problem of std::complex<_Tp>
	namespace complex_auto_casting
	{
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator *(complex<_tp1> x,_tp2 y)
		{
			return complex<_tp1>(_tp1{y})*x;
		}
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator *(_tp2 y,complex<_tp1> x)
		{
			return complex<_tp1>(_tp1{y})*x;
		}
		
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator +(complex<_tp1> x,_tp2 y)
		{
			return complex<_tp1>(_tp1{y})+x;
		}
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator +(_tp2 y,complex<_tp1> x)
		{
			return complex<_tp1>(_tp1{y})+x;
		}
		
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator /(complex<_tp1> x,_tp2 y)
		{
			return complex<_tp1>(_tp1{y})/x;
		}
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator /(_tp2 y,complex<_tp1> x)
		{
			return complex<_tp1>(_tp1{y})/x;
		}
		
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator -(complex<_tp1> x,_tp2 y)
		{
			return complex<_tp1>(_tp1{y})-x;
		}
		template<typename _tp1,typename _tp2>
		complex<_tp1> operator -(_tp2 y,complex<_tp1> x)
		{
			return complex<_tp1>(_tp1{y})-x;
		}
	}
	#ifndef NDEF_CAC
	using namespace complex_auto_casting;
	#endif
}
#endif
