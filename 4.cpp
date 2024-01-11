#include "train.cpp"

int main() {
    // Сидящий вагон без верхних мест
    Sitting sc(10, 0, 5, 0, false);
    // Есть все виды мест
    Platzkart pc(6, 6, 3, 3, false);
    // нет боковых мест
    Coupe cc(6, 6, 0, 0, true);
    // нет боковых и верхних мест
    SV svc(6, 0, 0, 0, true);

    PassengerTrain train;
    train.add(&sc);
    train.add(&pc);
    train.add(&cc);
    train.add(&svc);

    double profit = train.getTotalProfit();
    std::cout << "Профит от сидящего вагона: " << sc.getProfit() << std::endl;
    std::cout << "Профит от плацкартного вагона: " << pc.getProfit() << std::endl;
    std::cout << "Профит от купе: " << cc.getProfit() << std::endl;
    std::cout << "Профит от СВ: " << svc.getProfit() << std::endl;
    std::cout << "Профит от рейса: " << profit << std::endl;
    return 0;
}