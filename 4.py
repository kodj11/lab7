class TrainCar:
    def __init__(self, lower, upper, lower_side, upper_side, has_services):
        self.lower_seats = lower 
        self.upper_seats = upper
        self.lower_side_seats = lower_side
        self.upper_side_seats = upper_side
        self.has_additional_services = has_services
    
    def get_profit(self):
        pass

class PassengerCar(TrainCar):
    def __init__(self, lower, upper, lower_side, upper_side, has_services):
        super().__init__(lower, upper, lower_side, upper_side, has_services)
        
class SittingCar(PassengerCar):
    lowerPrice = 111.05
    upperPrice = 0
    lowerSidePrice = 100.05
    upperSidePrice = 0
    def get_profit(self):
        return (self.lower_seats * self.lowerPrice +
                self.lower_side_seats * self.lowerSidePrice)

class PlatzkartCar(PassengerCar):
    lowerPrice = 121.2
    upperPrice = 100.2
    lowerSidePrice = 110.0
    upperSidePrice = 98.1
    def get_profit(self):
        return (self.lower_seats * self.lowerPrice +
                self.lower_side_seats * self.lowerSidePrice +
                self.upper_side_seats * self.upperSidePrice +
                self.upper_seats * self.upperPrice)

class CoupeCar(PassengerCar):
    lowerPrice = 141.05
    upperPrice = 120.21
    lowerSidePrice = 0
    upperSidePrice = 0
    def get_profit(self):
        return (self.lower_seats * self.lowerPrice +
                self.upper_seats * self.upperPrice)

class SvCar(PassengerCar):
    lowerPrice = 121.05
    upperPrice = 0
    lowerSidePrice = 0
    upperSidePrice = 0
    def get_profit(self):
        return (self.lower_seats * self.lowerPrice)

class PassengerTrain:
    def __init__(self):
        self.cars = []
        
    def add_car(self, car):
        self.cars.append(car)
        
    def get_total_profit(self):
        total = 0
        for car in self.cars:
            total += car.get_profit() 
        return total

train = PassengerTrain()

sc = SittingCar(10, 0, 5, 0, False)
pc = PlatzkartCar(6, 6, 3, 3, False) 
cc = CoupeCar(6, 6, 0, 0, True)
svc = SvCar (6, 0, 0, 0, True)

train.add_car(sc)
train.add_car(pc)
train.add_car(cc)
train.add_car(svc)

profit = train.get_total_profit()
print(f"Профит за сидящий: {sc.get_profit()}")
print(f"Профит за плацкарт: {pc.get_profit()}")
print(f"Профит за купе: {cc.get_profit()}")
print(f"Профит за СВ: {svc.get_profit()}")
print(f"Общий профит: {profit}")
