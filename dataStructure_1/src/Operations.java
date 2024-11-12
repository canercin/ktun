public class Operations {
    public  Foods seqAdd(Foods firstFood, String name, int weight, double price) {
        Foods newFood = new Foods();
        if(firstFood == null){
            firstFood = new Foods();
            firstFood.name = name;
            firstFood.weight = weight;
            firstFood.price = price;
            firstFood.nextFood = null;
            return firstFood;
        }
        else {
            Foods tempFood = firstFood;
            //add to the head of the list
            if(tempFood.price > price){
                newFood.name = name;
                newFood.weight = weight;
                newFood.price = price;
                newFood.nextFood = tempFood;
                return newFood;
            }
            else {
                while(tempFood.nextFood != null){
                    if(tempFood.nextFood.price > price && tempFood.price < price){
                        newFood.name = name;
                        newFood.weight = weight;
                        newFood.price = price;
                        newFood.nextFood = tempFood.nextFood;
                        tempFood.nextFood = newFood;
                        return firstFood;
                    }
                    tempFood = tempFood.nextFood;
                }
                newFood.name = name;
                newFood.weight = weight;
                newFood.price = price;
                tempFood.nextFood = newFood;
                return firstFood;
            }
        }
    }

    public static Foods delete(Foods firstFood, String name){
        Foods tempFood = firstFood;
        System.out.printf("%s isimli yemek ilk\n", firstFood.name);
        while (tempFood != null){
            if (firstFood.name.equalsIgnoreCase(name)) {
                //firstFood = firstFood.nextFood;
                Foods temp = firstFood.nextFood;
                System.out.printf("%s isimli yemek silindi\n", temp.name);
                return temp;
            }else if (tempFood.nextFood.name.equalsIgnoreCase(name)){
                tempFood.nextFood = tempFood.nextFood.nextFood;
                System.out.printf("%s yemeği menüden başarıyla kaldırıldı.\n", name);
                return firstFood;
            }
            tempFood = tempFood.nextFood;
        }
        return firstFood;
    }
    public static void printList(Foods foods) {
        Foods first = foods;
        while(foods != null) {
            System.out.println(foods.name + " " + foods.weight + " " + foods.price);
            foods = foods.nextFood;
        }
    }
    public static double find(String name, Foods fFood){
        while(fFood != null) {
            if(fFood.name.equalsIgnoreCase(name)){
                return fFood.price;
            }
            fFood = fFood.nextFood;
        }
        return 0;
    }

    public static Foods findLast(Foods firstFood){
        while (firstFood != null){
            if (firstFood.nextFood == null){
                return firstFood;
            }
            firstFood = firstFood.nextFood;
        }
        return firstFood;
    }
}
