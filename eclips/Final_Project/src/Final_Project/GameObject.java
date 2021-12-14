package Final_Project;


public class GameObject implements GameInterface{
	private int distance=1; // 한 번 이동 거리
	private int x, y; // 현재 위치(화면 맵 상의 위치)
	private String name;
	private int move_count=0;
	static char transfer = 2;
	
	synchronized public void fishmove() throws InterruptedException {
		//transfer이 1일 때 작동
		while(transfer!=1) {
			wait();
		}
		transfer=0;
		{
			this.move();
		}
		notifyAll();
	}
	synchronized public void bearmove() throws InterruptedException {
		//transfer이 2일때 작동
		while(transfer<2) {
			wait();
		}
		transfer=1;
		{
			this.move();
		}
		notifyAll();
	}
	synchronized public void waiting(GameObject bear,GameObject fish) throws InterruptedException {
		//transfer이 0일 때 작동
		while(transfer>0) {
			wait();
		}
		transfer=2;
		{
			System.out.println("현재 이동횟수 : "+this.move_count);
			for(int i=0;i<bear.ROW;i++) {
				for(int j=0;j<bear.COL;j++) {
					if(bear.getX()==i&&bear.getY()==j) System.out.print(bear.getShape());
					else if(fish.getX()==i&&fish.getY()==j) System.out.print(fish.getShape());
					else System.out.print('.');
				}
				System.out.println();
			}
		}
		notifyAll();
	}
	
	public void move() {
		// TODO Auto-generated method stub
		int c,xi,yi,news;
		news=(int)(Math.random()*4);
		for(int i=0;i<news;i++) {
			c=1;
			if((news+i)%4<2) c=-1;
			xi=yi=c;
			if(((news+i)%4)%2==1) xi=0;
			else yi=0;
			
			if(this.x+xi<0||this.x+xi>=this.ROW) continue;
			else if(this.y+yi<0||this.y+yi>=this.COL) continue;
			else {
				this.x+=this.distance*xi;
				this.y+=this.distance*yi;
				break;
			}
		}
		this.move_count++;
	}
	

	@Override
	public char getShape() {
		// TODO Auto-generated method stub
		char c;
		if(this.name.equals("bear")) c='B';
		else if(this.name.equals("fish")) c='@';
		else c='.';
		return c;
	}
	public void set(int startX, int startY) { 
		this.x = startX;
		this.y = startY;
		this.move_count=0;
	}
	public GameObject(int startX, int startY, String name) { 
		this.x = startX;
		this.y = startY;
		this.name = name;
	}
	public int getX() {
		return x;
	}
	public int getY() {
		return y;
	}
	public int getCount() {
		return move_count;
	}
	public boolean collide(GameObject p) { // 이 객체가 객체 p와 충돌했으면 true 리턴
		if (this.x == p.getX() && this.y == p.getY())
			return true;
		return false;
	}
}