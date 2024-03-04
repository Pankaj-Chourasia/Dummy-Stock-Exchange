# Dummy Stock Exchange (DSE) Project

This project is a simple implementation of a Dummy Stock Exchange (DSE) in C++, enhanced with additional features.

## Implemented Features

1. **Error Handling and Validation:**
   - Implemented robust error handling for user inputs to ensure data integrity.
   - Validated user inputs for stock symbols, prices, and quantities.

2. **User Interaction:**
   - Implemented a user-friendly menu system allowing users to easily interact with the program.
   - Provided options for buying, selling, checking the portfolio, and exiting the program.

3. **Persistent Data Storage:**
   - Integrated file I/O to save and load the trader's portfolio data.
   - Portfolio data is stored in a file ("portfolio_data.txt") for persistence across sessions.

## Work in Progress

4. **Additional Stock Information:**
   - In progress: Working on integrating live stock data using APIs.
   - Targeting APIs such as Alpha Vantage or Yahoo Finance to display real-time stock information.

## How to Run the Program

1. Clone the repository to your local machine:

   ```bash
   https://github.com/Pankaj-Chourasia/Dummy-Stock-Exchange.git
   ```
2. Compile the C++ code:
   ```bash
    g++ DSE.cpp -o stock_exchange
   ```
3. Run the executable:
   ```bash
      ./stock_exchange
   ```
## Usage
Follow the on-screen menu to perform various actions like buying, selling, checking the portfolio, and saving/loading data.
## Contributing
If you would like to contribute to this project, please follow the standard procedures:

- Fork the repository.
- Create a new branch for your feature (git checkout -b feature/new-feature).
- Commit your changes (git commit -m 'Add new feature').
- Push to the branch (git push origin feature/new-feature).
- Open a Pull Request.
## License
This project is licensed under the [MIT License](LICENSE.md).
