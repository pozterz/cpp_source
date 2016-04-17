/**
 * UVa 10901 - Ferry Loading III
 *
 * @author Kullawat Chaowanawatee <kullawat@coe.phuket.psu.ac.th>
*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Car
{
  int id;
  int arrivalTime;
};

int main()
{
  int cases;

  cin >> cases;

  while (cases--)
  {
    int capacity, turnTime, cars;

    cin >> capacity >> turnTime >> cars;

    queue<Car> left, right;
    vector<int> actualTime(cars, 0);
    int maxTime = turnTime;

    // read input and always keep the maximum loading time
    for (int car = 0; car < cars; car++)
    {
      int arrivalTime;
      string side;

      cin >> arrivalTime >> side;

      if (side == "left")
        left.push({car, arrivalTime});
      else
        right.push({car, arrivalTime});

      maxTime = max(maxTime, arrivalTime);
    }

    // At the beginning, time is 0 and starts at left side
    int currentTime = 0;
    bool isLeft = true;

    while (!left.empty() || !right.empty())
    {
      int onBoard = 0;
      int minTime = maxTime;

      // wait for first possible car
      if (!left.empty())
        minTime = min(minTime, left.front().arrivalTime);

      if (!right.empty())
        minTime = min(minTime, right.front().arrivalTime);

      currentTime = max(currentTime, minTime);

      // keep loading until full loaded
      while (onBoard < capacity)
      {
        bool isEmpty = (isLeft) ? left.empty() : right.empty();
        Car boardingCar = (isLeft) ? left.front() : right.front();

        // but if the car is not arrived or no more car,
        // we can't load anymore
        if (isEmpty || boardingCar.arrivalTime > currentTime)
          break;

        // load the car
        actualTime[boardingCar.id] = currentTime + turnTime;
        ++onBoard;

        if (isLeft) left.pop();
        else right.pop();
      }

      // cross the river side
      currentTime += turnTime;
      isLeft = !isLeft;
    }

    // show actual loading time of each car
    for (int i = 0; i < cars; i++)
      cout << actualTime[i] << "\n";

    if (cases)
      cout << "\n";
  }

  exit(EXIT_SUCCESS);
}
