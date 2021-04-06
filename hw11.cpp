
#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include "csc160.h"

using namespace std;
using std::ifstream;
using std::stringstream;

vector<string> splitLine(string line) {
  stringstream lineStream(line);
  string cell;
  vector<string> result;
  while(getline(lineStream, cell, ','))
  {
      result.push_back(cell);
  }
  return result;
}


double parseDouble(string value) {
  if (value == "NA") {
    return -9999;
  }
  size_t sz;
  double val = stod(value, &sz);
  return val;
}
vector<WeatherReport> getData() {
//open file stream that reads this file (already in our replit)
  ifstream str("cheyenne.csv");

  //data will go here
  vector<WeatherReport> data;

  string line;

  getline(str, line);//read header
  //loop until we get to the end of the file
  int i = 0;
  while (true) {
    getline(str,line);

    //line length will be zero when we get to end of file
    if (line.length() == 0) {
      //break exits the loop
      break;
    }

    if ( i >= 32873) {
      break;
    }
    i ++;
    vector<string> row = splitLine(line);
    WeatherReport report("");
    report.setTemperature(parseDouble(row[2]));
    report.setValidTime(row[1]);
    data.push_back(report);
  }
  return data;
}

double getAverage(vector<double> values) {
  double sum = 0;
  int count = 0;
  for (int i = 0; i < values.size(); i++) {
    if (values[i] != -9999) {
      sum += values[i];
      count += 1;
    }
  }
  if (count > 0) {
    return sum / count;
  } else {
    return -9999;
  }
}

/*STUDENT: write a function that will take a vector of weather report 
           and provide a daily temperature average
*/
vector<double> getDailyAverage(vector<WeatherReport> reports) {
  /*
    - Create empty map<string, vector<double>>
    - Loop through each report
      - Get the day for that report by substring validTime index 5
      - Check if that day already exists in map
      - If not, then create empty vector in the map for that day
      - Push back the temp value onto vector for that day

    - Create and empty vector to return
    - Loop through each day in the map
      - Get average for the day's vector
      - Push average value onto output vector
    - Return the vector
  */

}


int main() {
  vector<WeatherReport> reports = getData();
  vector<double> daily_avgs = getDailyAverage(reports);


  Plotter plotter;
  vector<vector<double>> plot_series;
  vector<string> series_names;

  plot_series.push_back(daily_avgs);
  series_names.push_back("daily averages");

  plotter.write_plot(plot_series, series_names, "Daily Avg", "daily_avg.png");
}