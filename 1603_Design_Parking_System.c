typedef struct {
    int* big;
    int* medium;
    int* small;
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* parking = (ParkingSystem*)malloc(sizeof(ParkingSystem));
    parking->big = (int*)malloc(sizeof(int*));
    parking->medium = (int*)malloc(sizeof(int*));
    parking->small = (int*)malloc(sizeof(int*));
    *parking->big = big;
    *parking->medium = medium;
    *parking->small = small;
    return parking;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
	if(carType == 1)
	{
		if(*obj->big >= 1)
		{
			*obj->big -= 1;
			return true;
		}
		return false;
	}
	if(carType == 2)
	{
		if(*obj->medium >= 1)
		{
			*obj->medium -= 1;
			return true;
		}
		return false;
	}
	if(carType == 3)
	{
		if(*obj->small >= 1)
		{
			*obj->small -= 1;
			return true;
		}
		return false;
	}
	return false;
}

void parkingSystemFree(ParkingSystem* obj) {
	free(obj->big);
	free(obj->medium);
	free(obj->small);
	free(obj);
}