package knu.java.hw05;

public class GameObject implements FishGameInterface{
	private int distance=1; // �� �� �̵� �Ÿ�
	private int x, y; // ���� ��ġ(ȭ�� �� ���� ��ġ)
	private String name;
	
	public void move(int news) {
		int c=1,xi,yi;
		if(news<2) c=-1;
		xi=yi=c;
		if(news%2==1) xi=0;
		else yi=0;
		
		if(this.x+xi<0||this.x+xi>=this.ROW) System.out.println("can't move");
		else if(this.y+yi<0||this.y+yi>=this.COL) System.out.println("can't move");
		else {
			this.x+=this.distance*xi;
			this.y+=this.distance*yi;
		}
	}
	
	public char getShape() {
		char c;
		if(this.name.equals("bear")) c='B';
		else if(this.name.equals("fish")) c='@';
		else c='.';
		return c;
	}
	// �ʱ� ��ġ�� �̵� �Ÿ� ����
	public GameObject(int startX, int startY, String name) { 
		this.x = startX-1;
		this.y = startY-1;
		this.name = name;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public boolean collide(GameObject p) { // �� ��ü�� ��ü p�� �浹������ true ����
		if (this.x == p.getX() && this.y == p.getY())
			return true;
		else
			return false;
	}
}
