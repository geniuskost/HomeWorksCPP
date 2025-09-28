#include "Reservoir.h"
#include <vector>
#include <fstream>

void saveText(const std::vector<Reservoir>& arr, const std::string& filename) {
    std::ofstream fout(filename);
    for (const auto& r : arr) {
        fout << r.getName() << " " << int(r.getType()) << " " << r.getWidth() << " " << r.getLength() << " " << r.getMaxDepth() << "\n";
    }
}

void saveBinary(const std::vector<Reservoir>& arr, const std::string& filename) {
    std::ofstream fout(filename, std::ios::binary);
    for (const auto& r : arr) {
        size_t len = r.getName().size();
        fout.write((char*)&len, sizeof(len));
        fout.write(r.getName().c_str(), len);
        int t = int(r.getType());
        fout.write((char*)&t, sizeof(t));
        double w = r.getWidth(), l = r.getLength(), d = r.getMaxDepth();
        fout.write((char*)&w, sizeof(w));
        fout.write((char*)&l, sizeof(l));
        fout.write((char*)&d, sizeof(d));
    }
}

ReservoirType inputType() {
    int t;
    std::cout << "Тип (0-море, 1-озеро, 2-ставок, 3-басейн): ";
    std::cin >> t;
    switch (t) {
        case 0: return ReservoirType::Sea;
        case 1: return ReservoirType::Lake;
        case 2: return ReservoirType::Pond;
        case 3: return ReservoirType::Pool;
        default: return ReservoirType::Unknown;
    }
}

int main() {
    std::vector<Reservoir> arr;
    while (true) {
        std::cout << "1-Додати\n2-Видалити\n3-Вивести\n4-Записати у текстовий файл\n5-Записати у бінарний файл\n0-Вихід\n";
        int ch; std::cin >> ch;
        if (ch == 0) break;
        if (ch == 1) {
            std::string name;
            double w, l, d;
            std::cout << "Назва: "; std::cin >> name;
            std::cout << "Ширина: "; std::cin >> w;
            std::cout << "Довжина: "; std::cin >> l;
            std::cout << "Макс. глибина: "; std::cin >> d;
            ReservoirType t = inputType();
            arr.emplace_back(name, w, l, d, t);
        } else if (ch == 2) {
            int idx; std::cout << "Номер: "; std::cin >> idx;
            if (idx > 0 && idx <= arr.size()) arr.erase(arr.begin() + idx - 1);
        } else if (ch == 3) {
            for (size_t i = 0; i < arr.size(); ++i) {
                std::cout << "№" << i + 1 << ":\n";
                arr[i].print();
            }
        } else if (ch == 4) {
            saveText(arr, "reservoirs.txt");
        } else if (ch == 5) {
            saveBinary(arr, "reservoirs.bin");
        }
    }
    return 0;
}