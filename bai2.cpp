#include <iostream>
#include <vector>
using namespace std;

class vemaybay
{
private:
    string tenchuyen;
    string ngaybay;
    float giave;

public:
    vemaybay() : tenchuyen(""), ngaybay(""), giave(0) {}

    ~vemaybay() {}

    void Nhap()
    {
        cout << "Nhap ten chuyen bay: ";
        cin.ignore();
        getline(cin, tenchuyen);
        cout << "Nhap ngay bay (dd/mm/yyyy): ";
        getline(cin, ngaybay);
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat() const
    {
        cout << "Ten chuyen bay: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    float getGiave() const
    {
        return giave;
    }
};

class Nguoi
{
private:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi() : hoten(""), gioitinh(""), tuoi(0) {}

    ~Nguoi() {}

    virtual void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    virtual void Xuat() const
    {
        cout << "\nHo ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class Hanhkhach : public Nguoi
{
private:
    vemaybay *ve;
    int soluong;

public:
    Hanhkhach() : Nguoi(), ve(nullptr), soluong(0) {}

    ~Hanhkhach()
    {
        delete[] ve;
    }

    void Nhap() override
    {
        Nguoi::Nhap();
        cout << "Nhap so luong ve: ";
        cin >> soluong;
        ve = new vemaybay[soluong];
        for (int i = 0; i < soluong; ++i)
        {
            cout << "\nNhap thong tin ve may bay thu " << i + 1 << endl;
            ve[i].Nhap();
        }
    }

    void Xuat() const override
    {
        Nguoi::Xuat();
        cout << "So luong ve: " << soluong << endl;
        for (int i = 0; i < soluong; ++i)
        {
            cout << "\nThong tin ve thu " << i + 1 << endl;
            ve[i].Xuat();
        }
        cout << "Tong tien phai tra: " << tongtien() << endl;
    }

    float tongtien() const
    {
        float tong = 0;
        for (int i = 0; i < soluong; ++i)
        {
            tong += ve[i].getGiave();
        }
        return tong;
    }
};

void NhapDanhSachHanhKhach(Hanhkhach *&ds, int &n)
{
    cout << "Nhap so luong hanh khach: ";
    cin >> n;

    ds = new Hanhkhach[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "\nNhap thong tin hanh khach thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void XuatDanhSachHanhKhach(Hanhkhach *ds, int n)
{
    cout << "\n--- Danh sach hanh khach ---\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "\nThong tin hanh khach thu " << i + 1 << ":\n";
        ds[i].Xuat();
    }
}

// sắp xếp danh sách hành khách theo tổng tiền giảm dần
void SapXepDanhSachHanhKhach(Hanhkhach *ds, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (ds[i].tongtien() < ds[j].tongtien())
            {
                swap(ds[i], ds[j]);
            }
        }
    }
}

int main()
{
    Hanhkhach *ds = NULL;
    int n;

    // Nhập danh sách hành khách
    NhapDanhSachHanhKhach(ds, n);

    // Hiển thị danh sách hành khách
    XuatDanhSachHanhKhach(ds, n);

    // Sắp xếp danh sách hành khách theo tổng tiền giảm dần
    SapXepDanhSachHanhKhach(ds, n);

    // Hiển thị danh sách sau khi sắp xếp
    cout << "\n--- Danh sach hanh khach sau khi sap xep theo tong tien giam dan ---\n";
    XuatDanhSachHanhKhach(ds, n);

    delete[] ds;
    return 0;
}