#include "train.cpp"

int main() {
    // ������� ����� ��� ������� ����
    Sitting sc(10, 0, 5, 0, false);
    // ���� ��� ���� ����
    Platzkart pc(6, 6, 3, 3, false);
    // ��� ������� ����
    Coupe cc(6, 6, 0, 0, true);
    // ��� ������� � ������� ����
    SV svc(6, 0, 0, 0, true);

    PassengerTrain train;
    train.add(&sc);
    train.add(&pc);
    train.add(&cc);
    train.add(&svc);

    double profit = train.getTotalProfit();
    std::cout << "������ �� �������� ������: " << sc.getProfit() << std::endl;
    std::cout << "������ �� ������������ ������: " << pc.getProfit() << std::endl;
    std::cout << "������ �� ����: " << cc.getProfit() << std::endl;
    std::cout << "������ �� ��: " << svc.getProfit() << std::endl;
    std::cout << "������ �� �����: " << profit << std::endl;
    return 0;
}