package knu.java.hw07;

import java.util.*;

class Order implements Comparable<Order> {
    
    private int id;
    private String name;
    private int count;

    public Order(int id, String name, int count) {
        this.id = id;
        this.name = name;
        this.count = count;
    }
    public String toString() {
		return "("+id+","+name+","+count+")";
	}
	public int compareTo(Order order) {
		return this.name.compareTo(order.getName());
	}
    public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id=id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name=name;
	}
	public int getCount() {
		return count;
	}
	public void setCount(int count) {
		this.count=count;
	}
}

public class Homework2 {
    
    public static void main(String[] args) {
        String[] names = { "아메리카노", "카페라떼", "아메리카노", "카페라떼", "에스프레소" };
        int[] counts = { 2, 3, 1, 2, 3 };
        
        List<Order> orders = new ArrayList<Order>();
        for (int i = 0; i < names.length; i++) {
            orders.add(new Order(i + 1, names[i], counts[i]));
        }
        System.out.println(orders);
        
        HashMap<String, Integer> orderMap = new HashMap<String, Integer>();
        for (Order order: orders) {
            String key = order.getName();
            Integer value = orderMap.get(key);
            if(value==null) value=0;
            value=value+order.getCount();
            orderMap.put(key,value);
        }
        System.out.println(orderMap);
    }
    
}


