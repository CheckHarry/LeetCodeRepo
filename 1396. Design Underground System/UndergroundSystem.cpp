#include <unordered_map>
#include <string>
using namespace std;

class UndergroundSystem
{
public:
    unordered_map<int, pair<string, double>> record;
    unordered_map<string, pair<double, double>> stats;
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        record[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        int time = t - record[id].second;
        string key = record[id].first + '_' + stationName;

        stats[key].first += (stats[key].first * stats[key].second + time) / (stats[key].second + 1);
        stats[key].second++;

        record.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        string key = startStation + '_' + endStation;
        return stats[key].first;
    }
};