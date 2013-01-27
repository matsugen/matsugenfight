package sprite_window;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;

import javax.swing.ButtonGroup;
import javax.swing.DefaultComboBoxModel;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;

import org.dyno.visual.swing.layouts.Bilateral;
import org.dyno.visual.swing.layouts.Constraints;
import org.dyno.visual.swing.layouts.GroupLayout;
import org.dyno.visual.swing.layouts.Leading;
import org.dyno.visual.swing.layouts.Trailing;

//VS4E -- DO NOT REMOVE THIS LINE!
public class Window1 extends JFrame {

	private static final long serialVersionUID = 1L;
	private JRadioButton jRadioButton1;
	private JRadioButton jRadioButton0;
	private JComboBox jComboBox0;
	private ButtonGroup bg;
	//Sprite_Numberとそのモデル
	private JList jList0;
	private DefaultListModel model0;
	//
	private JScrollPane jScrollPane0;
	private JButton jButton0;
	private JButton jButton1;
	private JPanel jPanel0;
	private JList jList1;
	private JScrollPane jScrollPane1;
	private JLabel jLabel1;
	private JLabel jLabel0;
	private JButton jButton2;
	private JLabel jLabel2;
	private JTextField jTextField1;
	private JLabel jLabel3;
	private JTextField jTextField2;
	private JLabel jLabel4;
	private JTextField jTextField0;
	private JButton jButton3;
	//listenerメンバ
	private ButtonAction Baction;
	private Attack attack;
	private static final String PREFERRED_LOOK_AND_FEEL = "javax.swing.plaf.metal.MetalLookAndFeel";
	public Window1() {
		attack=new Attack();
		attack.Serializer("test");
		initComponents();
	}
/*
 * Actionlistenerを設定する
 */
	//Buttonのアクションリスナー
	class ButtonAction implements ActionListener{
		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO 自動生成されたメソッド・スタブ
			//Push FileLoad
			if(e.getSource()==jButton0){
				//jFileChooserクラスを用いてファイルをロード
			}
			//Push FileSave
			if(e.getSource()==jButton1){
				//jFileChooserクラスを用いてファイルをセーブ
			}
			//Push LoadImage
			if(e.getSource()==jButton2){
				//jFileChooserクラスとimageクラス?を用いてがぞうを分割読み込み
			}
			//Push Collision Reload
			if(e.getSource()==jButton3){
				//Window2のデータで構造体を更新
			}
		}
	};
//
	private void initComponents() {
		setLayout(new GroupLayout());
		add(getJRadioButton0(), new Constraints(new Leading(599, 10, 10), new Trailing(12, 12, 12)));
		add(getJRadioButton1(), new Constraints(new Leading(657, 12, 12), new Trailing(12, 12, 12)));
		add(getJButton1(), new Constraints(new Leading(107, 10, 10), new Trailing(12, 54, 54)));
		add(getJButton0(), new Constraints(new Leading(16, 10, 10), new Trailing(11, 54, 54)));
		add(getJPanel0(), new Constraints(new Leading(3, 581, 12, 12), new Bilateral(2, 48, 0)));
		add(getJComboBox0(), new Constraints(new Leading(602, 101, 12, 12), new Trailing(50, 62, 468)));
		add(getJScrollPane0(), new Constraints(new Leading(599, 107, 12, 12), new Leading(28, 202, 10, 10)));
		add(getJLabel1(), new Constraints(new Leading(586, 10, 10), new Leading(239, 24, 10, 10)));
		add(getJLabel0(), new Constraints(new Leading(590, 12, 12), new Leading(6, 87, 87)));
		add(getJButton2(), new Constraints(new Leading(194, 12, 12), new Trailing(11, 54, 54)));
		add(getJLabel2(), new Constraints(new Leading(299, 10, 10), new Trailing(16, 54, 54)));
		add(getJTextField1(), new Constraints(new Leading(313, 33, 12, 12), new Trailing(15, 54, 54)));
		add(getJLabel3(), new Constraints(new Leading(352, 12, 12), new Trailing(16, 54, 54)));
		add(getJTextField2(), new Constraints(new Leading(365, 36, 12, 12), new Trailing(15, 54, 54)));
		add(getJLabel4(), new Constraints(new Leading(407, 12, 12), new Trailing(16, 54, 54)));
		add(getJTextField0(), new Constraints(new Leading(421, 37, 12, 12), new Trailing(15, 54, 54)));
		add(getJScrollPane1(), new Constraints(new Leading(598, 100, 12, 12), new Leading(265, 148, 10, 10)));
		add(getJButton3(), new Constraints(new Leading(592, 12, 12), new Leading(425, 87, 87)));
		initBg();
		//ButtonListenerの追加
		Baction=new ButtonAction();
		jButton0.addActionListener(Baction);
		jButton1.addActionListener(Baction);
		jButton2.addActionListener(Baction);
		jButton3.addActionListener(Baction);
		//ListListenerここまで
		setTitle("Main Window");
		setSize(720, 540);
	}

	private JButton getJButton3() {
		if (jButton3 == null) {
			jButton3 = new JButton();
			jButton3.setText("CollisionReload");
		}
		return jButton3;
	}

	private JTextField getJTextField0() {
		if (jTextField0 == null) {
			jTextField0 = new JTextField();
			jTextField0.setText("0");
		}
		return jTextField0;
	}

	private JLabel getJLabel4() {
		if (jLabel4 == null) {
			jLabel4 = new JLabel();
			jLabel4.setText("N");
		}
		return jLabel4;
	}

	private JTextField getJTextField2() {
		if (jTextField2 == null) {
			jTextField2 = new JTextField();
			jTextField2.setText("0");
		}
		return jTextField2;
	}

	private JLabel getJLabel3() {
		if (jLabel3 == null) {
			jLabel3 = new JLabel();
			jLabel3.setText("Y");
		}
		return jLabel3;
	}

	private JTextField getJTextField1() {
		if (jTextField1 == null) {
			jTextField1 = new JTextField();
			jTextField1.setText("0");
		}
		return jTextField1;
	}

	private JLabel getJLabel2() {
		if (jLabel2 == null) {
			jLabel2 = new JLabel();
			jLabel2.setText("X");
		}
		return jLabel2;
	}

	private JButton getJButton2() {
		if (jButton2 == null) {
			jButton2 = new JButton();
			jButton2.setText("LoadImage");
		}
		return jButton2;
	}

	private JLabel getJLabel0() {
		if (jLabel0 == null) {
			jLabel0 = new JLabel();
			jLabel0.setText("Sprite_number");
		}
		return jLabel0;
	}

	private JLabel getJLabel1() {
		if (jLabel1 == null) {
			jLabel1 = new JLabel();
			jLabel1.setText("Collision_number");
		}
		return jLabel1;
	}

	private JScrollPane getJScrollPane1() {
		if (jScrollPane1 == null) {
			jScrollPane1 = new JScrollPane();
			jScrollPane1.setViewportView(getJList1());
		}
		return jScrollPane1;
	}

	private JList getJList1() {
		if (jList1 == null) {
			jList1 = new JList();
			DefaultListModel listModel = new DefaultListModel();
			jList1.setModel(listModel);
		}
		return jList1;
	}

	private JPanel getJPanel0() {
		if (jPanel0 == null) {
			jPanel0 = new JPanel();
			jPanel0.setBackground(Color.lightGray);
			jPanel0.setLayout(new GroupLayout());
			jPanel0.addMouseListener(new MouseAdapter() {

			});
		}
		return jPanel0;
	}

	private JButton getJButton1() {
		if (jButton1 == null) {
			jButton1 = new JButton();
			jButton1.setText("FileSave");
		}
		return jButton1;
	}

	private JButton getJButton0() {
		if (jButton0 == null) {
			jButton0 = new JButton();
			jButton0.setText("FileLoad");
		}
		return jButton0;
	}

	private JScrollPane getJScrollPane0() {
		if (jScrollPane0 == null) {
			jScrollPane0 = new JScrollPane();
			jScrollPane0.setViewportView(getJList0());
		}
		return jScrollPane0;
	}

	private JList getJList0() {
		if (jList0 == null) {
			jList0 = new JList();
			model0 = new DefaultListModel();
			DefaultListModel listModel = new DefaultListModel();
			jList0.setModel(listModel);
		}
		return jList0;
	}

	private void initBg() {
		bg = new ButtonGroup();
		bg.add(getJRadioButton0());
		bg.add(getJRadioButton1());
	}

	private JComboBox getJComboBox0() {
		if (jComboBox0 == null) {
			jComboBox0 = new JComboBox();
			jComboBox0.setModel(new DefaultComboBoxModel(new Object[] { "Hit", "Attack", "Push", "State" }));
			jComboBox0.setDoubleBuffered(false);
			jComboBox0.setBorder(null);
		}
		return jComboBox0;
	}

	private JRadioButton getJRadioButton0() {
		if (jRadioButton0 == null) {
			jRadioButton0 = new JRadioButton("",true);
			jRadioButton0.setText("add");
		}
		return jRadioButton0;
	}

	private JRadioButton getJRadioButton1() {
		if (jRadioButton1 == null) {
			jRadioButton1 = new JRadioButton();
			jRadioButton1.setText("edit");
		}
		return jRadioButton1;
	}

	private static void installLnF() {
		try {
			String lnfClassname = PREFERRED_LOOK_AND_FEEL;
			UIManager.setLookAndFeel(lnfClassname);
		} catch (Exception e) {
			System.err.println("Cannot install " + PREFERRED_LOOK_AND_FEEL + " on this platform:" + e.getMessage());
		}
	}

	/**
	* Main entry of the class.
	* Note: This class is only created so that you can easily preview the result at runtime.
	* It is not expected to be managed by the designer.
	* You can modify it as you like.
	*/
	public static void main(String[] args) {
		installLnF();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				Window1 frame1 = new Window1();
				Window2 frame2 = new Window2();
				frame1.setDefaultCloseOperation(Window1.EXIT_ON_CLOSE);
				frame1.setTitle("Window1");
				frame1.getContentPane().setPreferredSize(frame1.getSize());
				frame1.pack();
				frame1.setLocationRelativeTo(null);
				frame1.setVisible(true);
				frame2.setDefaultCloseOperation(Window2.EXIT_ON_CLOSE);
				frame2.setTitle("Window2");
				frame2.getContentPane().setPreferredSize(frame2.getSize());
				frame2.pack();
				frame2.setLocationRelativeTo(null);
				frame2.setVisible(true);
			}
		});
	}


}
