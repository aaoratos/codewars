#include <vector>
#include <string>

class Kata {
public:
    std::vector<std::string> towerBuilder(int nFloors) {
        int TowerWidth = nFloors * 2 - 1;
        int StarsPerFloor = 0;
        int PaddingWidth = 0;
        std::vector<std::string> Result;
        std::string Floor;

        for (int i = 0; i < nFloors; i++) {
            StarsPerFloor = i * 2 + 1;
            PaddingWidth = (TowerWidth - StarsPerFloor) / 2;
            Floor = "";
            for (int j = 0; j < TowerWidth; j++) {
                if (j < PaddingWidth || j >= (PaddingWidth + StarsPerFloor)) {
                    Floor += " ";
                } else {
                    Floor += "*";
                }
            }
            Result.push_back(Floor);
        }
        return Result;
    }
};