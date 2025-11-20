class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double K = celsius + 273.15;
        double F = celsius * 1.80 + 32.00;
        vector<double> v;
        v.push_back(K);
        v.push_back(F);
        return v;
    }
};