#include <bits/stdc++.h>
using namespace std;

class TaiLieu {
private:
    string maTL;
    string tenTL;
    //string loaiTL;
    //int timeMuon;
public:
    TaiLieu() {}
    TaiLieu(string _ma, string _ten) {
        this->maTL = _ma;
        this->tenTL = _ten;
    }
    //virtual void setLoai() = 0;
    virtual string getLoai() = 0;
    virtual double getGiaMuon() = 0;
    virtual int getSL() = 0;
    void setMaTL(string ma) {
        this->maTL = ma;
    }
    string getMaTL() {
        return this->maTL;
    }
    void setTenTL(string ten) {
        this->tenTL = ten;
    }
    string getTenTL() {
        return this->tenTL;
    }
    void xuat() {
        cout << "Mã tài liệu: " << getMaTL() << endl;
        cout << "Tên tài liệu: " << getTenTL() << endl;
        cout << "Loại tài liệu: " << getLoai() << endl;
        cout << "Số lượng còn: " << getSL() << endl;
        cout << "Đơn giá: " << getGiaMuon() << endl;
    }
};

class Sach : public TaiLieu {
private:
    string loaiSach;
    int soQuyen;
public:
    Sach() {}
    Sach(string _ma, string _ten, string _loai, int _soQuyen) 
    : TaiLieu(_ma, _ten), loaiSach(_loai), soQuyen(_soQuyen) {}
    void setSoQuyen(int _quyen) {
        this->soQuyen = _quyen;
    }
    int getSL() {
        return this->soQuyen;
    }
    void setLoai(string _loai) {
        this->loaiSach = _loai;
    }
    string getLoai() {
        return this->loaiSach;
    }
    double getGiaMuon() {
        if (this->loaiSach == "SachGiaoKhoa" || this->loaiSach == "SachThamKhao") {
            return 6000;
        }
        else if (this->loaiSach == "TapChi") {
            return 7000;
        }
        return 5000;
    }
};

class DeAn : public TaiLieu {
private:
    string loaiDeAn;
    int soTrang;
public:
    DeAn() {}
    DeAn(string _ma, string _ten, string _loai, int _soTrang) 
    : TaiLieu(_ma, _ten), loaiDeAn(_loai), soTrang(_soTrang) {}
    void setSoTrang(int _trang) {
        this->soTrang = _trang;
    }
    int getSoTrang() {
        return this->soTrang;
    }
    void setLoai(string _loai) {
        this->loaiDeAn = _loai;
    }
    string getLoai() {
        return this->loaiDeAn;
    }
    double getGiaMuon() {
        return this->soTrang*200;
    }
    int getSL() {
        return this->soTrang;
    }
};

class DocGia {
private:
    string maDG;
    string tenDG;
    //TaiLieu* vecTL[100];
    int timeMuon;
public:
    DocGia() {}
    DocGia(string _ma, string _ten, int _time) {
        this->maDG = _ma;
        this->tenDG = _ten;
        this->timeMuon = _time;
    }
    void setMaDG(string _ma) {
        this->maDG = _ma;
    }
    string getMaDG() {
        return this->maDG;
    }
    void setTenDG(string _ten) {
        this->tenDG = _ten;
    }
    string getTenDG() {
        return this->tenDG;
    }
    void setTimeMuon(int _time) {
        this->timeMuon = _time;
    }
    int getTimeMuon() {
        return this->timeMuon;
    }
    
    friend istream& operator >> (istream& is, DocGia& dg) {
        getline(cin, dg.tenDG);
        is >> dg.maDG >> dg.timeMuon;
        //is.ignore();
        return is;
    }
    
    friend ostream& operator << (ostream& os, DocGia dg) {
        os << "Mã độc giả: " << dg.maDG << endl;
        os << "Tên độc giả: " << dg.tenDG << endl;
        os << "Thời gian mượn: " << dg.timeMuon << endl;
        os << "Tổng tiền phải trả: ";
        return os;
    }
    
};

TaiLieu* vecTL[100];

void KhoiTao() {
        vecTL[0] = new Sach("TL001", "Sach 1", "SachGiaoKhoa", 5);
        vecTL[1] = new DeAn("TL002", "DeAn 1", "KHMT", 50);
        vecTL[2] = new Sach("TL003", "Sach 2", "SachThamKhao", 3);
        vecTL[3] = new DeAn("TL004", "DeAn 2", "CNPM", 70);
        vecTL[4] = new Sach("TL005", "Sach 3", "SachGiaoKhoa", 4);
        vecTL[5] = new DeAn("TL006", "DeAn 3", "HTTT", 60);
        vecTL[6] = new Sach("TL007", "Sach 4", "SachThamKhao", 2);
        vecTL[7] = new DeAn("TL008", "DeAn 4", "HTTT", 80);
        vecTL[8] = new Sach("TL009", "Sach 5", "SachGiaoKhoa", 3);
        vecTL[9] = new DeAn("TL010", "DeAn 5", "KHMT", 90);
        vecTL[10] = new Sach("TL011", "Sach 6", "TapChi", 2);
        vecTL[11] = new DeAn("TL012", "DeAn 6", "CNPM", 100);
        vecTL[12] = new Sach("TL013", "Sach 7", "Truyen", 5);
        vecTL[13] = new DeAn("TL014", "DeAn 7", "KHMT", 70);
        vecTL[14] = new Sach("TL015", "Sach 8", "TieuThuyet", 3);
        vecTL[15] = new DeAn("TL016", "DeAn 8", "HTTT", 60);
        vecTL[16] = new Sach("TL017", "Sach 9", "TieuThuyet", 2);
        vecTL[17] = new DeAn("TL018", "DeAn 9", "CNPM", 50);
        vecTL[18] = new Sach("TL019", "Sach 10", "SachThamKhao", 4);
        vecTL[19] = new DeAn("TL020", "DeAn 10", "HTTT", 80);
}
    
void xuatDSTL() {
    for (int i=0; i<20; i++) {
        vecTL[i]->xuat();
    }
}
    
Sach* checkSach(string maTL, int soQuyen) {
    for (int i = 0; i < 20; i++) {
        if (vecTL[i] != nullptr && vecTL[i]->getMaTL() == maTL&& vecTL[i]->getSL() >= soQuyen) {
            Sach* s = new Sach(maTL, vecTL[i]->getTenTL(), vecTL[i]->getLoai(), vecTL[i]->getSL() - soQuyen);   
            vecTL[i] = s;
            return s;
        }
    }
    return nullptr;
}
    
DeAn* checkDeAn(string maTL) {
    for (int i = 0; i < 20; i++) {
    if (vecTL[i] != nullptr && vecTL[i]->getMaTL() == maTL&& vecTL[i]->getSL() > 0) {
            DeAn* d = new DeAn(maTL, vecTL[i]->getTenTL(), vecTL[i]->getLoai(), vecTL[i]->getSL());   
            vecTL[i] = new DeAn(maTL, vecTL[i]->getTenTL(), vecTL[i]->getLoai(), 0);
            return d;
        }
    }
    return nullptr;
}

int main() {
    DocGia dg[100]; int idx = 0;
    KhoiTao();
    int option;
    do {
        //DocGia dg; 
        //KhoiTao();
        cin >> dg[idx];
        cin.ignore();
        double total = 0;
        string cmdline, _maTL;
        getline(cin, cmdline);
        stringstream ss(cmdline);
        int choice; ss >> choice;
        switch(choice) {
            case 1:
                xuatDSTL();
                break;
            case 2:
                while (ss >> _maTL) {
                    if ( int(_maTL[_maTL.length()-1]) % 2 != 0) {
                        int _soQuyen; ss >> _soQuyen;
                        // check tồn tại
                        Sach* s = checkSach(_maTL, _soQuyen);
                        if (s != nullptr) {
                            total += s->getGiaMuon() * _soQuyen;
                            //cout << "Sach check" << endl;
                        }
                        else {
                            cout << "Mã tài liệu " << _maTL << " không còn đủ số lượng bạn cần" << endl;
                        }
                        //
                    }
                    else if (int(_maTL[_maTL.length()-1]) % 2 == 0) {
                        DeAn* d = checkDeAn(_maTL);
                        if (d != nullptr) {
                            total += d->getGiaMuon();
                            //cout << "deAn check" << endl;
                        }
                        else {
                            cout << "Mã tài liệu " << _maTL << " không còn đủ số lượng bạn cần" << endl;
                        }
                    }
                }
                if (dg[idx].getTimeMuon() - 5 <= 0) {
                    total = 0;
                }
                else {
                    total *= dg[idx].getTimeMuon() - 5;
                }
                cout << dg[idx] << total << endl;
                cout << "-----------------------------------" << endl;
                break;
            case 3:
                while(ss >> _maTL) {
                if ( int(_maTL[_maTL.length()-1]) % 2 != 0) {
                    Sach* s = checkSach(_maTL, 0);
                    if (s != nullptr) {
                        s->xuat();
                    }
                    else {
                        cout << "Mã tài liệu " << _maTL << " không tồn tại" << endl;
                    }
                    //
                }
                else if (int(_maTL[_maTL.length()-1]) % 2 == 0) {
                    DeAn* d = checkDeAn(_maTL);
                    if (d != nullptr) {
                        d->xuat();
                    }
                    else {
                        cout << "Mã tài liệu " << _maTL << " không tồn tại" << endl;
                    }
                }
                cout << "------------------------------------" << endl;}
            default:
                break;
        }
        cin >> option;
        cin.ignore();
        idx++;
    } while (option == 1);
    return 0;
}
