import java.util.Scanner;
 
public class VendingMachine {
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int quantity = 0;
        double price;
        double totalPrice;
        double money;
        double change;
        String item;
        //String array of items available in the vending machine 
        String[] items = {"snack1", "snack2", "snack3", "snack4", "soda1", "soda2", "soda3", "soda4", "candy1", "candy2", "candy3", "candy4"};
       //Integer array of quantity available for each item in the vending machine 
       int[] quantityAvailable = {15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15};
       //Double array of prices for each item in the vending machine 
        double[] prices = {0.75, 0.75, 0.75, 0.75, 0.50, 0.50, 0.50, 0.50, 0.25, 0.25, 0.25, 0.25};
        //Boolean to indicate whether the vending machine is online or offline 
        boolean online = false;
        int totalQuantity;
        //Integer array to store the quantity of each item sold 
        int[] quantitySold = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //String array to store the transaction history 
        String[] transactionHistory = new String[20];
        //Integer to store the total number of transactions 
        int transactionNumber = 0;
        //Integer array to store the quantity of expired items 
        int[] expiredItemsQuantity = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //Integer to store the total quantity of expired items 
        int totalExpiredQuantity = 0;
        //Integer array to store the quantity of items to be restocked 
        int[] itemsToRestock = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        //Integer to store the total quantity of items to be restocked
        int totalRestockQuantity = 0;
        //Welcome message 
        System.out.println("Welcome to Vending Machine!");
        //Loop to display menu options
        while (true) {
            System.out.println("1. Info");
            System.out.println("2. Recommendations");
            System.out.println("3. Purchase History");
            System.out.println("4. Restocker");
            System.out.println("Press ESC to exit");
 //Input for menu options 
            String input = in.nextLine();
 //If statement to display vending machine info 
            if (input.equals("1")) {
                System.out.println("Vending Machine Name: VEND-O-MATIC");
                System.out.println("Location: 123 Main Street");
                System.out.println("Serial Number: 1234567");
                System.out.println("Model Number: VEND-123");
                //If statement to display status of vending machine 
                if (online) {
                    System.out.println("Status: Online");
                } else {
                    System.out.println("Status: Offline");
                }
                System.out.println("Toggle switch: I to toggle on, O to toggle off");
                //If statement to display recommendations 
            } else if (input.equals("2")) {
                for (int i = 0; i < items.length; i++) {
                    //If statement to display recommendation to drop price 
                    if (quantitySold[i] < 5) {
                        System.out.println("Recommendation: Drop price of " + items[i]);
                        //If statement to display recommendation to increase price 
                    } else if (quantitySold[i] > 10) {
                        System.out.println("Recommendation: Increase price of " + items[i]);
                        //If statement to display no recommendation
                    } else {
                        System.out.println("No recommendation for " + items[i]);
                    }
                }
                //If statement to display purchase history 
            } else if (input.equals("3")) {
                for (int i = 0; i < transactionHistory.length; i++) {
                    if (transactionHistory[i] != null) {
                        System.out.println("Transaction " + (i + 1) + ": " + transactionHistory[i]);
                    }
                }
                //If statement to display restocker menu 
            } else if (input.equals("4")) {
                System.out.println("Total Inventory:");
                totalQuantity = 0;
                for (int i = 0; i < items.length; i++) {
                    System.out.println(items[i] + ": " + quantityAvailable[i]);
                    totalQuantity += quantityAvailable[i];
                }
                System.out.println("Total Quantity: " + totalQuantity);
                System.out.println("Type the name of the item to restock or type ESC to exit");
                //Input for restocker menu
                String itemInput = in.nextLine();
                //Loop to restock items 
                while (!itemInput.equals("ESC")) {
                    boolean found = false;
                    for (int i = 0; i < items.length; i++) {
                        //If statement for item to restock 
                        if (items[i].equals(itemInput)) {
                            found = true;
                            System.out.println("How many of " + itemInput + "?");
                            int restockQuantity = in.nextInt();
                            //If statement to prevent overstocking items 
                            if (restockQuantity > 15) {
                                System.out.println("Error: Item is overstocked");
                            } else {
                                itemsToRestock[i] = restockQuantity;
                                totalRestockQuantity += restockQuantity;
                                System.out.println("Item " + itemInput + " restocked with " + restockQuantity + " quantity");
                            }
                        }
                    }
                    //If statement to display error if item not found
                    if (!found) {
                        System.out.println("Error: Item not found");
                    }
                    System.out.println("Type the name of the item to restock or type ESC to exit");
                    itemInput = in.nextLine();
                }
                //If statement to exit the program
            } else if (input.equals("ESC")) {
                break;
            } else {
                System.out.println("Error: Invalid option");
            }
        }
 //Loop to buy items
        while (true) {
            totalPrice = 0;
            System.out.println("What item do you want to buy? (Type ESC to exit)");
            item = in.nextLine();
            //If statement to exit the program 
            if (item.equals("ESC")) {
                break;
            }
            boolean foundItem = false;
            for (int i = 0; i < items.length; i++) {
                //If statement to purchase items 
                if (items[i].equals(item) && quantityAvailable[i] > 0) {
                    foundItem = true;
                    quantity = 1;
                    price = prices[i];
                    totalPrice = quantity * price;
                    System.out.println("How many " + item + "? (Max " + quantityAvailable[i] + ")");
                    quantity = in.nextInt();
                    if (quantity > quantityAvailable[i]) {
                        System.out.println("Error: Not enough quantity");
                        break;
                    }
                    //If statement to display error if not enough quantity
                    totalPrice = quantity * price;
                    System.out.println("Total price of " + quantity + " " + item + ": " + totalPrice);
                }
            }
            //if no item found in stock to print error
            if (!foundItem) {
                System.out.println("Error: Item not found or out of stock");
                break;
            }
            System.out.println("How much money do you have? (Format 0.00)");
            money = in.nextDouble();
            if (money < totalPrice) {
                System.out.println("Error: Not enough money");
                break;
            }
            change = money - totalPrice;
            if (foundItem) {
                for (int i = 0; i < items.length; i++) {
                    if (items[i].equals(item)) {
                        quantityAvailable[i] -= quantity;
                        quantitySold[i] += quantity;
                    }
                }
                if (change > 0) {
                    System.out.println("Your change: " + change);
                }
                System.out.println("Thank you for your purchase!");
                transactionHistory[transactionNumber] = "Item: " + item + ", Quantity: " + quantity + ", Total Price: " + totalPrice + ", Money: " + money + ", Change: " + change;
                transactionNumber++;
            }
        }
        
        for (int i = 0; i < items.length; i++) {
            if (quantityAvailable[i] > 0 && quantitySold[i] == 0) {
                expiredItemsQuantity[i] = quantityAvailable[i];
                quantityAvailable[i] = 0;
                totalExpiredQuantity += expiredItemsQuantity[i];
            }
        }
        //print the total restock quantity
        System.out.println("Total restock quantity: " + totalRestockQuantity);
        for (int i = 0; i < items.length; i++) {
            if (itemsToRestock[i] > 0) {
                quantityAvailable[i] += itemsToRestock[i];
            }
        }
        //print total expired quantity
        System.out.println("Total expired quantity: " + totalExpiredQuantity);
        System.out.println("Expired items:");
        for (int i = 0; i < items.length; i++) {
            if (expiredItemsQuantity[i] > 0) {
                System.out.println(items[i] + ": " + expiredItemsQuantity[i]);
            }
        }
    }
}