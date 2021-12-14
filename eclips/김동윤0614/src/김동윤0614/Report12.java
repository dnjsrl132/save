package �赿��0614;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.lang.Thread;
import java.lang.Runnable;
import java.util.Random;

public class Report12 extends JFrame {
   Report12() {
      super("�����带 ���� �׺�");
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      setContentPane(new GamePanel()); //GamePanel�� ����Ʈ������ ���
      setSize(300, 200);
      setVisible(true);
   }
   class GamePanel extends JPanel {
      //ȭ�� ������
      JLabel[] label = new JLabel[3]; //3���� ���̺�
      JLabel result = new JLabel("���콺�� Ŭ���� ������ �����մϴ�."); //��� ���
      /* TO DO ������(thread) ���� */
      public GamePanel() {
         setLayout(null); //���� ��ġ�� ������Ʈ ��ġ
         for(int i=0; i<label.length; i++) {
            label[i] = new JLabel("0"); //�ʱ� ���̺� ����
            label[i].setSize(60, 30); //���̺� ũ��
            label[i].setLocation(30+80*i, 50); //���̺� ��ġ
            label[i].setHorizontalAlignment(JLabel.CENTER);
            label[i].setOpaque(true); //���̺� ���� ������ �����ϵ��� ����
            label[i].setBackground(Color.MAGENTA);   
            label[i].setForeground(Color.YELLOW);
            label[i].setFont(new Font("Tahoma", Font.ITALIC, 30));
            add(label[i]);
         }
         result.setHorizontalAlignment(JLabel.CENTER); //����� ����� ���̺� ����
         result.setSize(250, 20);
         result.setLocation(30, 120);
         add(result);
         /* TO DO ������ ���� */
         GamblingThread thread = new GamblingThread(label, result);
         addMouseListener(new MouseAdapter() { //���콺 ������ ����
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
      JLabel[] label; //���� ���ڸ� ���
      JLabel result; //����� ���
      long delay = 200;//�����ð�(sleep) ��
      boolean gambling = false; //������ �� ������ ����
      public GamblingThread(JLabel[] label, JLabel result) {
         //TO DO
         this.label = label;
         this.result = result;
      }
      boolean isReady() {
         return !gambling; //���� ���̸� �غ���� �ʾ���
      }
      synchronized public void waitForGambling() {//�������� ������ ��ٸ�
    	  while(!gambling) {
    		  try {
				wait();
    		  }catch (InterruptedException e) {}
    	  }
    	  gambling=false;
    	  {
    		  //System.out.println("�����");
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
    		  //System.out.println("������");
    	  }
    	  notifyAll();
         //���콺 Ŭ������ ������ ����   
         //TO DO
         //start();
      }
      public void run() {
         //������ ����    
         //TO DO
         double dValue = Math.random() * 1000000;
         int c = ((int)dValue)%10;
         dValue = dValue/10;
         int b = (int)dValue%10;
         dValue = dValue/10;
         int a = (int)dValue%10;

         //ù��°, �ι�°, ����° �� ����
         label[0].setText(Integer.toString(a));
         label[1].setText(Integer.toString(b));
         label[2].setText(Integer.toString(c));
         
         //������ �����Ͽ����� �Ǻ�(�����մϴ�!! �Ǵ� �ƽ�����)
         if (a == b && b == c) {
            result.setText("�����մϴ�!!");
            System.out.println(a);
         }
         else {
            result.setText("�ƽ�����");
         }
      }
   }
   
   public static void main(String[] arg) {
      new Report12();
   }
}