#include <iostream>
using namespace std;

const int MAX_STOCKS = 100;

struct Stock {
    string symbol;
    double price;
    double initialPrice;
    int quantity;
};

class Trader {
private:
    Stock portfolio[MAX_STOCKS];
    int numOfStocks;
    double overallProfitLoss;

public:
    Trader() {
        this->numOfStocks =0;
        this->overallProfitLoss= 0;
    }
    void buyStock(string symbol, double price, int quantity) {
        if (numOfStocks < MAX_STOCKS) {
            portfolio[numOfStocks] = {symbol, price, price, quantity}; 
            ++numOfStocks;
            cout << quantity << " shares of " << symbol << " at ₹" << price << " each bought successfully.✓\n";
        } else {
            cout << "Error: Portfolio is full. Cannot buy more stocks.✗\n";
        }
    }

    void sellStock(string symbol, int quantity, double sellingPrice) {
        bool stockFound = false;
        for (int i = 0; i < numOfStocks; i++) {
            if (portfolio[i].symbol == symbol) {
                stockFound = true;
                if (portfolio[i].quantity >= quantity) {
                    portfolio[i].quantity -= quantity;

                    double buyingPrice = portfolio[i].initialPrice;
                    double profitLoss = (sellingPrice - buyingPrice) * quantity;
                    cout << quantity << " shares of " << symbol << " at ₹" << sellingPrice << " each sold successfully.✓\n";
                    if (profitLoss > 0) {
                        cout << "Profit: ₹"<<profitLoss << ".\n";
                    } else if (profitLoss < 0) {
                        cout << "Loss: ₹" << -profitLoss << ".\n";
                    } else {
                        cout << "No profit or loss.\n";
                    }
                    overallProfitLoss += profitLoss;
                } else {
                    cout << "Error: Insufficient stocks for selling.✗\n";
                }
                break;
            }
        }

        if (!stockFound) {
            cout << "Error: Stock not found.✗\n";
        }
    }

    double getPortfolioValue() {
        double totalValue = 0;
        for (int i = 0; i < numOfStocks; i++) {
            totalValue += portfolio[i].price * portfolio[i].quantity;
        }
        return totalValue;
    }

    void calculateOverallProfitLoss() {
        cout << "Overall Profit/Loss: ₹" << overallProfitLoss << ".\n";
    }
};

int main() {
    Trader trader;
    cout << "~~!!---- Welcome to Dummy Stock Exchange(DSE)----!!~~\n\n";
    trader.buyStock("AMZN", 12648.83, 30);
    trader.buyStock("RELIANCE", 2587.00, 15);
    trader.buyStock("TATAMOTORS", 779.40, 60);
    
    trader.sellStock("AMZN", 10, 12000);
    trader.sellStock("RELIANCE", 4, 2500.78);
    trader.sellStock("TCS", 45, 89);
    
    trader.calculateOverallProfitLoss();
    cout << "Portfolio Value: ₹" << trader.getPortfolioValue() << endl;

    return 0;
}
