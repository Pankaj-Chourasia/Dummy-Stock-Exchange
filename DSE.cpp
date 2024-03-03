#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

const int MAX_STOCKS = 100;
const string FILENAME = "portfolio_data.txt";

struct Stock
{
    string symbol;
    double price;
    double initialPrice;
    int quantity;
};

class Trader
{
private:
    Stock portfolio[MAX_STOCKS];
    int numOfStocks;
    double overallProfitLoss;

public:
    Trader()
    {
        this->numOfStocks = 0;
        this->overallProfitLoss = 0;
        loadPortfolioFromFile();
    }

    void showError(const string &message)
    {
        cout << "Error: " << message << " ✗\n";
    }

    bool isValidSymbol(const string &symbol)
    {
        // Add validation logic here (e.g., checking against a list of valid symbols)
        return true; // For simplicity, assuming all symbols are valid for now
    }

    bool isValidQuantity(int quantity)
    {
        return quantity > 0;
    }

    bool isValidPrice(double price)
    {
        return price > 0;
    }

    void buyStock()
    {
        string symbol;
        double price;
        int quantity;

        cout << "Enter stock symbol: ";
        cin >> symbol;

        if (!isValidSymbol(symbol))
        {
            showError("Invalid stock symbol.");
            return;
        }

        cout << "Enter stock price: ";
        cin >> price;

        if (!isValidPrice(price))
        {
            showError("Invalid stock price.");
            return;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        if (!isValidQuantity(quantity))
        {
            showError("Invalid quantity.");
            return;
        }

        if (numOfStocks < MAX_STOCKS)
        {
            portfolio[numOfStocks] = {symbol, price, price, quantity};
            ++numOfStocks;
            cout << quantity << " shares of " << symbol << " at ₹" << price << " each bought successfully.✓\n";
        }
        else
        {
            showError("Portfolio is full. Cannot buy more stocks.");
        }
    }

    void sellStock()
    {
        string symbol;
        int quantity;
        double sellingPrice;

        cout << "Enter stock symbol: ";
        cin >> symbol;

        bool stockFound = false;
        for (int i = 0; i < numOfStocks; i++)
        {
            if (portfolio[i].symbol == symbol)
            {
                stockFound = true;

                cout << "Enter quantity to sell: ";
                cin >> quantity;

                if (portfolio[i].quantity >= quantity && isValidQuantity(quantity))
                {
                    cout << "Enter selling price: ";
                    cin >> sellingPrice;

                    if (!isValidPrice(sellingPrice))
                    {
                        showError("Invalid selling price.");
                        return;
                    }

                    double buyingPrice = portfolio[i].initialPrice;
                    double profitLoss = (sellingPrice - buyingPrice) * quantity;
                    cout << quantity << " shares of " << symbol << " at ₹" << sellingPrice << " each sold successfully.✓\n";

                    if (profitLoss > 0)
                    {
                        cout << "Profit: ₹" << profitLoss << ".\n";
                    }
                    else if (profitLoss < 0)
                    {
                        cout << "Loss: ₹" << -profitLoss << ".\n";
                    }
                    else
                    {
                        cout << "No profit or loss.\n";
                    }
                    overallProfitLoss += profitLoss;
                    updateStockPrice(i);
                    break;
                }
                else
                {
                    showError("Invalid input for selling stocks.");
                }
            }
        }

        if (!stockFound)
        {
            showError("Stock not found.");
        }
    }

    void savePortfolioToFile()
    {
        ofstream file(FILENAME);

        if (file.is_open())
        {
            file << numOfStocks << endl;
            file << overallProfitLoss << endl;

            for (int i = 0; i < numOfStocks; i++)
            {
                file << portfolio[i].symbol << " "
                     << portfolio[i].price << " "
                     << portfolio[i].initialPrice << " "
                     << portfolio[i].quantity << endl;
            }

            file.close();
            cout << "Portfolio data saved successfully.✓\n";
        }
        else
        {
            showError("Error: Unable to open file for saving portfolio data.✗\n");
        }
    }

    void loadPortfolioFromFile()
    {
        ifstream file(FILENAME);

        if (file.is_open())
        {
            file >> numOfStocks;
            file >> overallProfitLoss;

            for (int i = 0; i < numOfStocks; i++)
            {
                file >> portfolio[i].symbol >> portfolio[i].price >> portfolio[i].initialPrice >> portfolio[i].quantity;
            }

            file.close();
            cout << "Portfolio data loaded successfully.✓\n";
        }
        else
        {
            cout << "No previous portfolio data found. Starting with an empty portfolio.\n";
        }
    }

    void checkPortfolio()
    {
        cout << "Portfolio Summary:\n";
        for (int i = 0; i < numOfStocks; i++)
        {
            cout << "Symbol: " << portfolio[i].symbol << ", Quantity: " << portfolio[i].quantity
                 << ", Average Price: ₹" << fixed << setprecision(2) << portfolio[i].initialPrice << "\n";
        }
        cout << "Overall Profit/Loss: ₹" << overallProfitLoss << ".\n";
        cout << "Portfolio Value: ₹" << getPortfolioValue() << "\n";
    }

    double getPortfolioValue()
    {
        double totalValue = 0;
        for (int i = 0; i < numOfStocks; i++)
        {
            totalValue += portfolio[i].price * portfolio[i].quantity;
        }
        return totalValue;
    }

    void calculateOverallProfitLoss()
    {
        cout << "Overall Profit/Loss: ₹" << overallProfitLoss << ".\n";
    }

    void updateStockPrice(int index)
    {
        double newPrice;

        cout << "Enter the updated price for stock " << portfolio[index].symbol << ": ";
        cin >> newPrice;

        if (isValidPrice(newPrice))
        {
            cout << "Stock price for " << portfolio[index].symbol << " updated successfully.✓\n";
            portfolio[index].price = newPrice;
        }
        else
        {
            showError("Invalid updated price. Stock price not updated.✗");
        }
    }
};

int main()
{
    Trader trader;
    int choice;

    do
    {
        cout << "\n~~!!---- Dummy Stock Exchange(DSE) Menu ----!!~~\n";
        cout << "1. Buy Stock\n";
        cout << "2. Sell Stock\n";
        cout << "3. Check Portfolio\n";
        cout << "4. Save Portfolio\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            trader.buyStock();
            break;

        case 2:
            trader.sellStock();
            break;

        case 3:
            trader.checkPortfolio();
            break;

        case 4:
            trader.savePortfolioToFile();
            break;

        case 5:
            cout << "Exiting the program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
