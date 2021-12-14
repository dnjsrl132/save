package 김동윤0614;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Thread;
import java.lang.Runnable;
import java.util.Random;

public class Report12 extends JFrame {
   Report12() {
      super("쓰레드를 가진 겜블링");
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setContentPane(new GamePanel()); //GamePanel을 컨텐트팬으로 등록
      setSize(300, 200);
      setVisible(true);
   }
   class GamePanel extends JPanel {
      //화면 디자인
      JLabel[] label = new JLabel[3]; //3개의 레이블
      JLabel result = new JLabel("마우스를 클릭할 때마다 게임합니다."); //결과 출력
      /* TO DO 스레드(thread) 생성 */
      public GamePanel() {
         setLayout(null); //절대 위치에 컴포넌트 배치
         for(int i=0; i<label.length; i++) {
            label[i] = new JLabel("0"); //초기 레이블 생성
            label[i].setSize(60, 30); //레이블 크기
            label[i].setLocation(30+80*i, 50); //레이블 위치
            label[i].setHorizontalAlignment(JLabel.CENTER);
            label[i].setOpaque(true); //레이블에 배경색 설정이 가능하도록 설정
            label[i].setBackground(Color.MAGENTA);   
            label[i].setForeground(Color.YELLOW);
            label[i].setFont(new Font("Tahoma", Font.ITALIC, 30));
            add(label[i]);
         }
         result.setHorizontalAlignment(JLabel.CENTER); //결과를 출력할 레이블 생성
         result.setSize(250, 20);
         result.setLocation(30, 120);
         add(result);
         /* TO DO 쓰레드 시작 */
         GamblingThread thread = new GamblingThread(label, result);
         addMouseListener(new MouseAdapter() { //마우스 리스너 구현
            public void mousePressed(MouseEvent e) {
               if((thread).isReady()) {
                  thread.startGambling();
               }
               thread.waitForGambling();
            }
         });
      }
   }
   class GamblingThread extends Thread {
      JLabel[] label; //게임 숫자를 출력
      JLabel result; //결과를 출력
      long delay = 200;//지연시간(sleep) 값
      boolean gambling = false; //게임을 할 것인지 결정
      public GamblingThread(JLabel[] label, JLabel result) {
         //TO DO
         this.label = label;
         this.result = result;
      }
      boolean isReady() {
         return !gambling; //게임 중이면 준비되지 않았음
      }
      synchronized public void waitForGambling() {//게임하지 않으면 기다림
    	  while(!gambling) {
    		  try {
				wait();
    		  }catch (InterruptedException e) {}
    	  }
    	  gambling=false;
    	  {
    		  //System.out.println("대기중");
    	  }
    	  notifyAll();
         //TO DO
      }
      synchronized public void startGambling(){
    	  while(gambling) {
    		  try {
				wait();
    		  }catch (InterruptedException e) {}
    	  }
    	  gambling=true;
    	  {
    		  run();
    		  //System.out.println("게임중");
    	  }
    	  notifyAll();
         //마우스 클릭으로 게임을 진행   
         //TO DO
         //start();
      }
      public void run() {
         //게임을 진행    
         //TO DO
         double dValue = Math.random() * 1000000;
         int c = ((int)dValue)%10;
         dValue = dValue/10;
         int b = (int)dValue%10;
         dValue = dValue/10;
         int a = (int)dValue%10;

         //첫번째, 두번째, 세번째 수 조정
         label[0].setText(Integer.toString(a));
         label[1].setText(Integer.toString(b));
         label[2].setText(Integer.toString(c));
         
         //게임이 성공하였는지 판별(축하합니다!! 또는 아쉽군요)
         if (a == b && b == c) {
            result.setText("축하합니다!!");
            System.out.println(a);
         }
         else {
            result.setText("아쉽군요");
         }
      }
   }
   
   public static void main(String[] arg) {
      new Report12();
   }
}