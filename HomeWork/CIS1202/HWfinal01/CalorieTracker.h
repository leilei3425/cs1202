#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

enum FoodCategory {
	Fruits,      // 0
	Vegetables,  // 1
	Grains,      // 2
	Protein,     // 3
	Dairy,       // 4
	Sweets,      // 5
	Beverages    // 6
};

enum MealType {
	breakfast,
	lunch,
	dinner,
	snack
};

struct Date {
	int year;
	int month;
	int day;
	// Constructor
	Date() {
		year = 0;
		month = 0;
		day = 0;
	}
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
};

class CalorieTracker {
protected:
	Date date;
	FoodCategory foodCategory;
	int calories;

public:
	CalorieTracker();
	CalorieTracker(Date, FoodCategory, int);

	void setDate(Date);
	void setFoodCategory(FoodCategory);
	void setCalories(int);

	Date getDate();
	FoodCategory getFoodCategory();
	int getCalories() const;

	virtual void displayEntry() const;
};


// Derived class that adds a meal type
class DetailedCalorieTracker : public CalorieTracker {
private:
	MealType mealType; // breakfast, lunch, dinner, snack

public:
	DetailedCalorieTracker();
	DetailedCalorieTracker(Date, FoodCategory, int, MealType);

	void setMealType(MealType);
	MealType getMealType();

	void displayEntry() const override;

};
