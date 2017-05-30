# Task

This folder contains all the tasks ongoing and completed.

# StockandWarehouse
This particular task involves creating a Graph containing Warehouses and a drop location. The Warehouses are pickup locations from which various stocks are needed to be collected and a drop location to which it can be dropped. The Current version is made specifically for a particular case in which there are three Warehouse locations and one drop location, this particular problem can be further simplified quite easily.

There are 3 centers C1, C2 and C3 which act as warehouses and stock products in the following way.One or all of these can deliver their respective products A, B, C, D, E, F, G, H or I to a customer location L1 depending upon the order request from customer. But only one delivery vehicle would be deployed (from either C1, C2 or C3) to fulfill this request.
The distance between C1, C2, C3 and L1 is as follows:

1. One and only one delivery vehicle would be deployed, either from C1, C2 or C3 to fulfill the order
2. In case orders from multiple centers need to fulfilled, this same vehicle would then pickup from different locations and then deliver to L1. However, it is not necessary that all pickups must be made before final delivery. It can be C1 (start)->L1 (drop)->C3 (pick up)->L1(drop)
3. The cost of running the vehicle as follows

Input:
  values of stocks in order: a b c d e f g h i
Output:
  The minimum cost according to the conditions
  
  Example:
  Input: 1 2 3 4 5 6 7 8 9
  Output: 1384
  Input: 1 0 0 2 1 0 2 0 1
  Output: 300
