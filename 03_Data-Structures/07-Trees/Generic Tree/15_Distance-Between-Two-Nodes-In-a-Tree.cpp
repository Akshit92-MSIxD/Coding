// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1 (Min distance between two given nodes of a Binary Tree)

// Note : Uppar wala Problem link jo hai wo Binary Tree Ke liye hai or tu use dekhiyo pehle phir  GTree wala solution bana liyo (easy hai :))

// Prerequiste : 14_Lowest-Common-Ancestor-of-GTree :)

/* Approach 1 : ==> Find the root to node path / node to root path for both a and b separately
                ==> Then traverse both the paths and Find the LCA node
                ==> Then check how far the LCA node is from a and b in their respective NodeToRootPath/RootToNodePath
                ==> Then add both the distance/difference to get the minimum distance between a and b :)
                ==> TC : O(n) , SC : O(H)[recursive] + additional vector space to store NodeToRootPath/RootToNodePath
*/

/* Approach 2 : ==> Find the LCA for a and b directly using only one recursive function  without storing their NodeToRootPath/RootToNodePath:)
                ==> Then we have to find the distance of a and b individually!!! from LCA node by using extra recursive function
                ==> Then add both the distance to get the minimum distance between a and b :)
                ==> TC : O(3n) , SC : O(H)[recursive]
*/




