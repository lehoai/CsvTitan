# CsvTitan

CsvTitan is a high-performance C++ library designed for handling extremely large CSV files with SQL-like functions. The primary focus of CsvTitan is to improve processing speed for large datasets. The library is written entirely in pure standard C++ and does not use any third-party libraries.

## Features

1. **Sort** (Completed)
   - Efficiently sorts large CSV files.

2. **Join** (In Progress)
   - Enables joining multiple CSV files based on common columns.

3. **Filter with Simple Queries** (In Progress)
   - Provides functionality to filter rows using simple query syntax.

4. **Pivot** (In Progress)
   - Allows pivoting of data for summarization and analysis.

5. **Unit** (In Progress)
   - Comprehensive unit operations for CSV file manipulations.

## Supported Data Types

1. **Int** (Completed)
2. **Double** (Completed)
3. **String** (In Development)
4. **Datetime** (In Development)

## Compiler

CsvTitan uses CMake for building the library.

## Unit Testing

CsvTitan uses Gtest for unit testing.

## Test Results

### Sorting Test

- **Data File:** [2021_Yellow_Taxi_Trip_Data.csv](https://catalog.data.gov/dataset/2021-yellow-taxi-trip-data-jan-jul) (~33 million records)
- **Time Taken:** Approximately 7 minutes 20 seconds

## Contributions

Contributions are welcome! Please fork the repository and submit a pull request.

## License

CsvTitan is licensed under the MIT License.

---

Feel free to reach out if you have any questions or need further assistance. Happy coding!