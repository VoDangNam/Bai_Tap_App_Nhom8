#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>//de su dung stringstream 

using namespace std;
//HÀM  
bool Kiem_tra_ngay (int d, int m, int y)
    {
    	
        if (y<0)
        {
            return false;
        }
        else
        {
            if (m<1 || m>12)
            {
                return false;
            }
            else
            {
                if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 ||m==12)
                {
                    if (d<1 || d>31)
                    {
                        return false;
                    }
                }
                else if (m==4 || m==6 || m==9 || m==11)
                {
                    if (d<1 || d>30)
                    {
                        return false;
                    }
                }
                else if (m==2)
                {
                    if(y%4==0 && (y%400==0 || y%100!=0))
                    {
                        if (d<1 || d>29)
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (d<1 || d>28)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
bool kiemTraKyTu (string s)
{
    //kiem tra xem trong chuoi co chua ky tu so hay khong
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]==' ')
        {
            continue;
        }
        if ((s[i]<'a' || s[i]>'z') && (s[i] <'A' || s[i] > 'Z')) //neu khong thuoc cac ky tu chu thi tra ve false
        {
            return false;
        }
    }
    return true;
}
string format(string name)
{
    //chinh lai phong chu cho phu hop cac chu cai dau viet hoa va giua cac chu chi co 1 dau cach
    int n=name.length();
    //Xoa dau cach
    for(int i=0; i<n; i++)
    {
        if(name[0]==' ')
        {
            for (int k=0; k<n; k++)
            {
                name[k] = name[k+1];
            }
            n--;
            i--;
        }
        if(name[i]==' '&&name[i+1]==' ')
        {
            for (int k=i; k<n; k++)
            {
                name[k] = name[k+1];
            }
            n--;
            i--;
        }
    }
    name[n] = '\0';
    //Viet hoa cac chu cai dau
    for (int i=0; i<n; i++)
    {
        if(name[0]>='a'&&name[0]<='z')
        {
            name[0]-=32;
        }
        if (name[i-1]==' ' && name[i]>='a' && name[i]<='z')
        {
            name[i]-=32;
        }
        if (name[i-1]!=' ' && name[i]>='A' && name[i]<='Z')
        {
            name[i]+=32;
        }
    }
    return name;
}

