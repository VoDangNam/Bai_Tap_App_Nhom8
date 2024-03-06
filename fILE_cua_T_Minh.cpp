
bool kiemTraMa(string s)
{
    for (int i=0; i<s.length(); i++)
    {
        if ((s[i]<'a' || s[i]>'z') && (s[i] <'A' || s[i] > 'Z') &&(s[i] <'0' || s[i] > '9') )
        {
            return false;
        }
    }
    return true;
}


//CLASSS
class Date{
	int d,m,y;
	public:
		 void nhap();
	     void xuat();
		
};

class Quan_ly_quan_cafe{
	protected:
		Date Ngay_nhap;
		string Ten_nguoi_nhap;
	public:
	virtual	void nhap();
	virtual	void xuat();
	
};

void Date::nhap(){
	
	do{
		
		do {
		 	 while (true)
            {
            	string inputD;
                  cout<<"\n\tNhap vao ngay : ";
                    getline(cin,inputD);
                stringstream day(inputD);
                if (day >> d && day.eof())
                {
                   
                    break;
                }
                cout << "Ngay khong hop le. Vui long nhap lai.\n";
            }
            if (cin.fail() || d <= 0&&d<1||d>31) 
				{
	                cout << "\n\tNgay khong hop le! Vui long nhap lai.\n";
	                 cout<<"\n\tNhap vao ngay : ";
	                cin>>d;
	                cin.clear();
	                cin.ignore(10000, '\n');
	            }
          } while (cin.fail() || d <= 0&&d<1||d>31);
	      
	    do {
		    	 while (true)
	            {
	            	string inputM;
	                 cout<<"\n\tNhap vao thang : ";
	                    getline(cin,inputM);
	                stringstream month(inputM);
	                if (month >> m && month.eof())
	                {
	                   
	                    break;
	                }
	                cout << "Thang khong hop le. Vui long nhap lai.\n";
	            }
	            if (cin.fail() || m <= 0&&m<1||m>12) 
				{
	                cout << "\n\tThang khong hop le! Vui long nhap lai.\n";
	                cout<<"\n\tNhap vao thang : ";
	                cin>>m;
	                cin.clear();
	                cin.ignore(10000, '\n');
	            }
            } while (cin.fail() || m <= 0&&m<1||m>12);
	        
	       do {
	       	 while (true)
	            {
	            	string inputY;
	                cout<<"\n\tNhap vao nam : ";
	                    getline(cin,inputY);
	                stringstream year(inputY);
	                if (year >> y && year.eof())
	                {
	                   
	                    break;
	                }
	                cout << "Nam khong hop le. Vui long nhap lai.\n";
	            }
            if (cin.fail() || y <= 0) {
            	
                cout << "\n\tNam khong hop le! Vui long nhap lai.\n";
                 cout<<"\n\tNhap vao nam : ";
	                cin>>y;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            
            } while (cin.fail() || y <= 0);
	    if(Kiem_tra_ngay(this->d,this->m,this->y)==false|| cin.fail())
	    {
	    	cout<<"Vui long nhap lai ngay thang nam \n";
		}
	      
	}while(Kiem_tra_ngay(this->d,this->m,this->y)==false|| cin.fail());
}

void Date::xuat(){
	cout<<d<<"/"<<m<<"/"<<y<<endl;
}
void Quan_ly_quan_cafe::nhap(){
	cout<<"\n\t\tNHAP THONG TIN NGUOI NHAP \t\t\n";
	Ngay_nhap.nhap();         
	 do{
	 	cout<<"\n\tNhap vao ten cua ban : ";
	 		        fflush(stdin);
	                getline(cin,Ten_nguoi_nhap);
		        if(kiemTraKyTu (Ten_nguoi_nhap) == false||Ten_nguoi_nhap.empty())
		        {
		        	cout<<"\n\tTen nguoi nhap da chua ki tu khong hop le !!!\n";
		        	cout<<"\n\tVui long nhap lai ";
				
				}
				
			}while (kiemTraKyTu (Ten_nguoi_nhap)==false||Ten_nguoi_nhap.empty()) ;
} 
void Quan_ly_quan_cafe::xuat(){
	
	cout<<"\n\tDa duoc "<<format(Ten_nguoi_nhap)<<endl;
	cout.width(25-Ten_nguoi_nhap.length());
	cout<<" Nhap vao ngay : ";
	Ngay_nhap.xuat();

}
class Quan_ly_nhan_vien : public Quan_ly_quan_cafe{
	private:
		string Ten_nhan_vien;
		string Chuc_vu;
		string Msnv;
		int So_gio_lam;
	
	public:
		void nhap()
		{
			Quan_ly_quan_cafe::nhap();
			cout << "\n\t+------------------------------------+\t\n" << endl;
       	    cout << "\n\t\tTHONG TIN NHAN VIEN\t\t\n" << endl;
			
			 do {
					    cout << "\n\tNhap vao ten nhan vien : ";
					    fflush(stdin);
					    getline(cin,Ten_nhan_vien);
					    if (kiemTraKyTu(Ten_nhan_vien) == false || Ten_nhan_vien.empty()) {
					        cout << "\n\tTen nhan vien da chua ki tu khong hop le hoac la rong!!!\n";
					        cout << "\n\tVui long nhap lai ";
					    }
				} while (kiemTraKyTu(Ten_nhan_vien) == false || Ten_nhan_vien.empty());
			
			do{
			 cout<<"\n\tNhap vao chuc vu cua "<<format(Ten_nhan_vien) <<" : ";
			fflush(stdin);
			getline(cin,Chuc_vu);
		        if(kiemTraKyTu (Chuc_vu) == false||Chuc_vu.empty())
		        {
		        	cout<<"\n\tChuc vu da chua ki tu khong hop le !!!\n";
		        	cout<<"\n\tVui long nhap lai ";
				}
				
			}while (kiemTraKyTu (Chuc_vu)==false||Chuc_vu.empty()) ;
			
			do{
				cout<<"\n\tNhap vao ma so nhan vien( Bao gom ca chu ) : ";
			   fflush(stdin);
			   getline(cin,Msnv);	
			}while(kiemTraMa(Msnv)==false||Msnv.empty());
			     
	    do {
		    	 while (true)
	            {
	            	string input;
	                cout<<"\n\tNhap vao so gio lam cua "<<format(Ten_nhan_vien)<<" trong hom nay : ";
                    getline(cin,input);
	                stringstream sgl(input);
	                if (sgl >> So_gio_lam && sgl.eof())
	                {
	                   
	                    break;
	                }
	                cout << "\n\tSo gio lam khong hop le !!.\n";
	                cout<<"\n\tNhap lai so gio lam : ";
			
	            }
			if (cin.fail() || So_gio_lam <= 0||So_gio_lam>24) 
				{
	                cout << "\n\tSo gio lam khong hop le !!..\n";
	                cout<<"\n\tNhap So gio lam : ";
	                cin>>So_gio_lam ;
	                cin.clear();
	                cin.ignore(10000, '\n');
	            }
	            
            } while (cin.fail() || So_gio_lam  <= 0||So_gio_lam >24);
		}
		void xuat(){
			Quan_ly_quan_cafe::xuat();
			cout << "+------------------------------------+\n" << endl;
			cout << "| Ten nhan vien : " << format(Ten_nhan_vien);
			cout.width(33 - Ten_nhan_vien.length());
			cout << " \n| Chuc vu : " << format(Chuc_vu);
			cout.width(36 - Chuc_vu.length());
			cout << " \n| Ma so nhan vien : " << Msnv;
			cout.width(31 - Msnv.length());
			cout << " \n| Tien luong cua " << format(Ten_nhan_vien) << " la : " << Tinh_tien_luong();
			cout << "\n+------------------------------------+" << endl;
		}
		
	string getter_msnv()
	{
		return Msnv;
	}
	float Tinh_tien_luong(){
		return So_gio_lam *20000;
		}
};

class Quan_ly_nguyen_lieu : public Quan_ly_quan_cafe {
private:
    string Ten_nguyen_lieu;
    float So_luong;
    float Gia;
    Date Thoi_gian_nhap;

public:
    void nhap() {
        Quan_ly_quan_cafe::nhap();
        cout << "\n\t+------------------------------------+\t\n" << endl;
       	cout << "\n\t\tTHONG TIN NGUYEN LIEU\t\t\n" << endl;
        do{
	          	cout<<"\n\tNhap vao ten nguyen lieu :";
		        fflush(stdin);
		        getline(cin,Ten_nguyen_lieu);
		        if(kiemTraKyTu (Ten_nguyen_lieu) == false||Ten_nguyen_lieu.empty())
		        {
		        	cout<<"\n\tTen nguyen lieu da chua ki tu khong hop le !!!";
		        	cout<<"\n\tVui long nhap lai ";
				}
			}while (kiemTraKyTu (Ten_nguyen_lieu)==false||Ten_nguyen_lieu.empty()) ;
         while (true)
            {
            	string input;
                	cout << "\n\tNhap vao so luong (KG) : ";
                getline(cin,input);
                stringstream sl(input);
                if (sl >> So_luong && sl.eof())
                {
                   
                    break;
                }
                cout << "So Luong  khong hop le. Vui long nhap lai.\n";
            }
         while (true)
            {
            	string input;
                cout << "\n\tNhap vao gia ( VND	): ";
                getline(cin,input);
                stringstream gia(input);
                if (gia >> Gia && gia.eof())
                {
                   
                    break;
                }
                cout << "Gia khong hop le. Vui long nhap lai.\n";
            }
        
        cout << "\n\tNhap vao Thoi gian nhap hang ve  ";
        Thoi_gian_nhap.nhap();

    }
   void xuat() {
    Quan_ly_quan_cafe::xuat();
    
    string line(55, '-');
    cout << "\n+" << line << "+";
    cout << "\n| Ten nguyen lieu: " << setw(37) << left << format(Ten_nguyen_lieu) ;
    cout << "\n| So luong: " <<  So_luong ;
    cout << "\n| Tong tien phai tra: " << Tinh_tien()<<" vnd\n" ;
    cout<<"| THOI GIAN NHAP HANG : ";
	Thoi_gian_nhap.xuat();
	cout << "+" << line << "+\n";
}
    float Tinh_tien() {
        return So_luong * Gia;
    }

};

class Quan_ly_don_hang:public Quan_ly_quan_cafe{
	private:
		int Gia=0;
		string Ten_mon;
		int So_luong=0;
		int Tong_tien=0;
		int tongsl=0; 
		int Gia2=0; 
		string Hinh_thuc_tra;
	public:
int sum;
	void nhaptv()
{
    Quan_ly_quan_cafe::nhap();
    int luachon;
    do{
    	system("cls") ;
        cout << "\n\t      MENU NUOC           \n";
	    cout << "\t||----------------------------||\n";
	    cout << "\t|| 1. Cafe Den   | 10,000 VND ||\n";
	    cout << "\t|| 2. Cafe Viet  | 15,000 VND ||\n";
	    cout << "\t|| 3. Bo Huc     | 20,000 VND ||\n";
	    cout << "\t|| 0. Thoat      |            ||\n";
	    cout << "\t||----------------------------||\n";             
        while (true)
        {
            string input;
            cout<<"\n\tNhap vao lua chon cua quy khach : ";
            getline(cin,input);
            stringstream lc(input);
            if (lc >>luachon  && lc.eof())
            {
                break;
            }
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        } 
        if(luachon==1)
        {
            cout<<"\n\tLua chon cua ban la Cafe Den ";
            while (true)
            {
                string input;
                cout << "\n\tNhap so luong : ";
                getline(cin,input);
                stringstream sl(input);
                if (sl >>So_luong&& sl.eof())
                {                   
                    break;
                }
                cout << "So luong khong hop le. Vui long nhap lai.\n";
            }
            Gia=So_luong*10000;
            Ten_mon="Cafe Den";
            Tong_tien += Gia; // add the price of this item to the total
            tongsl+=So_luong;
            Gia2+=Gia; 
        }
        else if(luachon==2)
        {
            cout<<"\n\tLuachon cua ban la Cafe Viet ";
            while (true)
            {
                string input;
                cout << "\n\tNhap so luong : ";
                getline(cin,input);
                stringstream sl(input);
                if (sl >>So_luong&& sl.eof())
                {                   
                    break;
                }
                cout << "So luong khong hop le. Vui long nhap lai.\n";
            }
            Gia=So_luong*15000;
            Ten_mon="Cafe Viet";   
            Tong_tien += Gia; // add the price of this item to the total
             tongsl+=So_luong;
              Gia2+=Gia; 
        }
        else if (luachon==3){
            cout<<"\n\tLua chon cua ban la Bo huc ";
            while (true)
            {
                string input;
                cout << "\n\tNhap so luong : ";
                getline(cin,input);
                stringstream sl(input);
                if (sl >>So_luong&& sl.eof())
                {                   
                    break;
                }
                cout << "So luong khong hop le. Vui long nhap lai.\n";
            }
            Gia=So_luong*20000;
            Ten_mon="Bo huc";
            Tong_tien += Gia; // add the price of this item to the total
             tongsl+=So_luong;
              Gia2+=Gia; 
        }
        else if (luachon==0){
            break;
        }
        cout<<"Tong tien :"<<Tong_tien<<" vnd\n";
    }while(luachon!=0);
    system("cls");
    cout << "\n\t\t||  CAC HINH THUC THANH TOAN ||\n";
    cout << "\t\t||-----------------------------||\n";
    cout << "\t\t||         A. Tien mat         ||\n";
    cout << "\t\t||         B. ATM              ||\n";
    cout << "\t\t||-----------------------------||\n"; 
	
    while(true)
    {

        do{
            cout << "\n\tNhap vao lua chon : ";
            cin>> Hinh_thuc_tra;
            if(kiemTraKyTu (Hinh_thuc_tra) == false||Hinh_thuc_tra.empty())
            {
                cout<<"\n\tBan da nhap chua ki tu khong hop le !!!\n";
                cout<<"\n\tVui long nhap lai ";   
            }
        }while(kiemTraKyTu (Hinh_thuc_tra) == false||Hinh_thuc_tra.empty()) ;
        if(Hinh_thuc_tra=="A" || Hinh_thuc_tra=="a")
        {
		int lcmgg;
        	cout<<"\t\t\t+========================================+\n" ;
			 cout<<"\t\tQuy khach co ma giam gia  hay khong ? \n";
			 cout<<"\t\t1. Co\n";
			 cout<<"\t\t2. Khong\n";
            while (true)
            {
            	string input;
                cout << "Nhap vao lua chon: ";
                getline(cin,input);
                stringstream lccc(input);
                if (lccc >>lcmgg && lccc.eof())
                {
                   
                    break;
                }
                //cout << "Lua chon khong hop le. Vui long nhap lai.\n";
            } 
            string mgg ; 
			 if(lcmgg==1)
			 {
			 	cout<<"\n\tNhap vao ma giam gia : ";
			 	fflush(stdin);
			 	getline(cin,mgg);
			 	cout<<"\n\tQUY KHACH DUOC NHAN UU DAI GIAM\t\n";
			 	cout<<"\n\tBan da chon hinh thuc thanh toan bang tien mat ";
	            cout<<"\n\tTong tien cua ban la : "<<Tong_tien-(Tong_tien*0.2)<<" vnd \n";
	            sum=Tong_tien-(Tong_tien*0.2);
	            break;
			 }
			 else if(lcmgg==2)
			 {
			 	cout<<"\n\tBan da chon hinh thuc thanh toan bang tien mat ";
	            cout<<"\n\tTong tien cua ban la : "<<Tong_tien<<" vnd \n";
	            sum=Tong_tien;
	            break;
			 }
            
        }
        else if(Hinh_thuc_tra=="B" || Hinh_thuc_tra=="b")
        { 
        int lcmggb;
        cout<<"\t\t\t+========================================+\n" ;
			 cout<<"\t\tQuy khach co ma giam gia  hay khong ? \n";
			 cout<<"\t\t1. Co\n";
			 cout<<"\t\t2. Khong\n";
			  while (true)
            {
            	string input;
                cout << "Nhap vao lua chon: ";
                getline(cin,input);
                stringstream lccc(input);
                if (lccc >>lcmggb && lccc.eof())
                {
                   
                    break;
                }
                //cout << "Lua chon khong hop le. Vui long nhap lai.\n";
            }
        if(lcmggb==1)
			 {
			 	string mgga;
			 	cout<<"\n\tNhap vao ma giam gia : ";
			 	fflush(stdin);
			 	getline(cin,mgga);
			 	cout<<"\n\tQUY KHACH DUOC NHAN UU DAI GIAM\t\n";
			 	cout<<"\n\tBan da chon hinh thuc thanh toan bang ATM ";
		            cout << "+-------------------------------------------+" << endl;
		            cout<<"\nTong tien cua ban la : "<<Tong_tien<<" vnd ";
		            cout << "+-------------------------------------------+" << endl;
		            system("cls");
		            cout<<"\nVui long thanh toan qua ma QR sau \n";
		            cout<<"\n\t\t\t***************************";
		            cout<<"\n\t\t\t***************************";
		            cout<<"\n\t\t\t****                   ****";
		            cout<<"\n\t\t\t****                   ****";
		            cout<<"\n\t\t\t****  ******   *****   ****";
		            cout<<"\n\t\t\t****  ** ***   ** **   ****";
		            cout<<"\n\t\t\t****  *******  **  **  ****";
		            cout<<"\n\t\t\t****                   ****";
		            cout<<"\n\t\t\t****                   ****" ;
		            cout<<"\n\t\t\t***************************" ;
		            cout<<"\n\t\t\t***************************";
		            cout<<"\n\tHOAC\n";
		            cout<<"\n\nSTK: 012345678**  (C++ BANK)\n" ;
		            cout<<"\nTong tien thanh toan cua quy khach la : "<<Tong_tien-(Tong_tien*0.2)<<" vdn\n\n";
		            sum=Tong_tien-(Tong_tien*0.2);
		            break;
			 }
			 else if(lcmggb==2)
			 {
			 	system("cls");
		            cout<<"\nVui long thanh toan qua ma QR sau \n";
		            cout<<"\n\t\t\t***************************";
		            cout<<"\n\t\t\t***************************";
		            cout<<"\n\t\t\t****                   ****";
		            cout<<"\n\t\t\t****                   ****";
		            cout<<"\n\t\t\t****  ******   *****   ****";
		            cout<<"\n\t\t\t****  ** ***   ** **   ****";
		            cout<<"\n\t\t\t****  *******  **  **  ****";
		            cout<<"\n\t\t\t****                   ****";
		            cout<<"\n\t\t\t****                   ****" ;
		            cout<<"\n\t\t\t***************************" ;
		            cout<<"\n\t\t\t***************************";
		            cout<<"\n\tHOAC\n";
		            cout<<"\n\nSTK: 012345678**  (C++ BANK)\n" ;
		            cout<<"\nTong tien thanh toan cua quy khach la : "<<Tong_tien<<" vdn\n\n";
		            sum=Tong_tien;
		            break;
	            break;
			 }
        }
    }   
}

void nhapta()
{
Quan_ly_quan_cafe::nhap();
int luachon;
do{
system("cls") ;
cout << "\n\t DRINK MENU \n";
cout << "\t||----------------------------||\n";
cout << "\t|| 1. Black Coffee | 10,000 VND ||\n";
cout << "\t|| 2. Vietnamese Coffee | 15,000 VND ||\n";
cout << "\t|| 3. RedBull | 20,000 VND ||\n";
cout << "\t|| 0. EXIT | ||\n";
cout << "\t||----------------------------||\n";
while (true)
{
string input;
cout<<"\n\tEnter your choice: ";
getline(cin,input);
stringstream lc(input);
if (lc >>luachon && lc.eof())
{
break;
}
cout << "Invalid choice. Please try again.\n";
}
if(luachon==1)
{
cout<<"\n\tYour choice is Black Coffee ";
while (true)
{
string input;
cout << "\n\tEnter quantity: ";
getline(cin,input);
stringstream sl(input);
if (sl >>So_luong&& sl.eof())
{
break;
}
cout << "Invalid quantity. Please try again.\n";
}
Gia=So_luong*10000;
Ten_mon="Black Coffee";
Tong_tien += Gia; // add the price of this item to the total
tongsl+=So_luong;
Gia2+=Gia;
}
else if(luachon==2)
{
cout<<"\n\tYour choice is Vietnamese Coffee ";
while (true)
{
string input;
cout << "\n\tEnter quantity: ";
getline(cin,input);
stringstream sl(input);
if (sl >>So_luong&& sl.eof())
{
break;
}
cout << "Invalid quantity. Please try again.\n";
}
Gia=So_luong*15000;
Ten_mon="Vietnamese Coffee";
Tong_tien += Gia; // add the price of this item to the total
tongsl+=So_luong;
Gia2+=Gia;
}
else if (luachon==3){
cout<<"\n\tYour choice is RedBull ";
while (true)
{
string input;
cout << "\n\tEnter quantity: ";
getline(cin,input);
stringstream sl(input);
if (sl >>So_luong&& sl.eof())
{
break;
}
cout << "Invalid quantity. Please try again.\n";
}
Gia=So_luong*20000;
Ten_mon="RedBull";
Tong_tien += Gia; // add the price of this item to the total
tongsl+=So_luong;
Gia2+=Gia;
}
else if (luachon==0){
break;
}
cout<<"Total amount: "<<Tong_tien<<" VND\n";
}while(luachon!=0);
system("cls");
cout << "\n\t\t|| PAYMENT METHODS ||\n";
cout << "\t\t||-----------------------------||\n";
cout << "\t\t|| A. Cash ||\n";
cout << "\t\t|| B. ATM ||\n";
cout << "\t\t||-----------------------------||\n";
while(true)
{

    do{
        cout << "\n\tEnter your choice: ";
        cin>> Hinh_thuc_tra;
        if(kiemTraKyTu (Hinh_thuc_tra) == false||Hinh_thuc_tra.empty())
        {
            cout<<"\n\tYou entered invalid characters!!!\n";
            cout<<"\n\tPlease try again ";   
        }
    }while(kiemTraKyTu (Hinh_thuc_tra) == false||Hinh_thuc_tra.empty()) ;
    if(Hinh_thuc_tra=="A" || Hinh_thuc_tra=="a")
    {
	int lcmgg;
    	cout<<"\t\t\t+========================================+\n" ;
		 cout<<"\t\tDo you have a discount code? \n";
		 cout<<"\t\t1. Yes\n";
		 cout<<"\t\t2. No\n";
        while (true)
        {
        	string input;
            cout << "Enter your choice: ";
            getline(cin,input);
            stringstream lccc(input);
            if (lccc >>lcmgg && lccc.eof())
            {
               
                break;
            }
            //cout << "Invalid choice. Please try again.\n";
        }
        string mgg ; 
		 if(lcmgg==1)
		 {
		 	cout<<"\n\tEnter the discount code: ";
		 	fflush(stdin);
		 	getline(cin,mgg);
		 	cout<<"\n\tYOU RECEIVED A DISCOUNT\t\n";
		 	cout<<"\n\tYou have chosen to pay by cash ";
            cout<<"\n\tYour total amount is: "<<Tong_tien-(Tong_tien*0.2)<<" VND \n";
            sum=Tong_tien-(Tong_tien*0.2);
            break;
		 }
		 else if(lcmgg==2)
		 {
		 	cout<<"\n\tYou have chosen to pay by cash ";
            cout<<"\n\tYour total amount is: "<<Tong_tien<<" VND \n";
            sum=Tong_tien;
            break;
		 }
        
    }
    else if(Hinh_thuc_tra=="B" || Hinh_thuc_tra=="b")
    { 
    int lcmggb;
    cout<<"\t\t\t+========================================+\n" ;
		 cout<<"\t\tDo you have a discount code? \n";
		 cout<<"\t\t1. Yes\n";
		 cout<<"\t\t2. No\n";
		  while (true)
        {
        	string input;
            cout << "Enter your choice: ";
            getline(cin,input);
            stringstream lccc(input);
            if (lccc >>lcmggb && lccc.eof())
            {
               
                break;
            }
            //cout << "Invalid choice. Please try again.\n";
        }
    if(lcmggb==1)
		 {
		 	string mgga;
		 	cout<<"\n\tEnter the discount code: ";
		 	fflush(stdin);
		 	getline(cin,mgga);
		 	cout<<"\n\tYOU RECEIVED A DISCOUNT\t\n";
		 	cout<<"\n\tYou have chosen to pay by ATM ";
	            cout << "+-------------------------------------------+" << endl;
	            cout<<"\nYour total amount is: "<<Tong_tien<<" VND ";
	            cout << "+-------------------------------------------+" << endl;
	            system("cls");
	            cout<<"\nPlease make payment through the following QR code: \n";
            cout<<"\n\t\t\t***************************";
            cout<<"\n\t\t\t***************************";
            cout<<"\n\t\t\t****                   ****";
            cout<<"\n\t\t\t****                   ****";
            cout<<"\n\t\t\t****  ******   *****   ****";
            cout<<"\n\t\t\t****  ** ***   ** **   ****";
            cout<<"\n\t\t\t****  *******  **  **  ****";
            cout<<"\n\t\t\t****                   ****";
            cout<<"\n\t\t\t****                   ****" ;
            cout<<"\n\t\t\t***************************" ;
            cout<<"\n\t\t\t***************************";
	            cout<<"\n\tOR\n";
	            cout<<"\n\nAccount number: 012345678**  (C++ BANK)\n" ;
	            cout<<"\nYour total payment amount is: "<<Tong_tien-(Tong_tien*0.2)<<" VDN\n\n";
	            sum=Tong_tien-(Tong_tien*0.2);
	            break;
		 }
		 else if(lcmggb==2)
		 {
		 	system("cls");
	            cout<<"\nPlease make payment through the following QR code: \n";
            cout<<"\n\t\t\t***************************";
            cout<<"\n\t\t\t***************************";
            cout<<"\n\t\t\t****                   ****";
            cout<<"\n\t\t\t****                   ****";
            cout<<"\n\t\t\t****  ******   *****   ****";
            cout<<"\n\t\t\t****  ** ***   ** **   ****";
            cout<<"\n\t\t\t****  *******  **  **  ****";
            cout<<"\n\t\t\t****                   ****";
            cout<<"\n\t\t\t****                   ****" ;
            cout<<"\n\t\t\t***************************" ;
            cout<<"\n\t\t\t***************************";
	            cout<<"\n\tOR\n";
	            cout<<"\n\nAccount number: 012345678**  (C++ BANK)\n" ;
	            cout<<"\nYour total payment amount is: "<<Tong_tien<<" VDN\n\n";
	            sum=Tong_tien;
	            break;
            break;
		 }
    }
}   
}

