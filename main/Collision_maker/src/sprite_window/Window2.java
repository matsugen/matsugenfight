package sprite_window;

import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;

import org.dyno.visual.swing.layouts.Bilateral;
import org.dyno.visual.swing.layouts.Constraints;
import org.dyno.visual.swing.layouts.GroupLayout;
import org.dyno.visual.swing.layouts.Leading;

//VS4E -- DO NOT REMOVE THIS LINE!
public class Window2 extends JFrame {

	private static final long serialVersionUID = 1L;
	private JCheckBox jCheckBox0;
	private JPanel jPanel0;
	private JTabbedPane jTabbedPane0;
	private JCheckBox jCheckBox1;
	private JTextField jTextField0;
	private JTextField jTextField1;
	private JLabel jLabel0;
	private JTextField jTextField2;
	private JTextField jTextField3;
	private JLabel jLabel1;
	private JPanel jPanel1;
	private JTextField jTextField4;
	private JTextField jTextField5;
	private JTextField jTextField6;
	private JTextField jTextField7;
	private JLabel jLabel2;
	private JLabel jLabel3;
	private JTextField jTextField8;
	private JTextField jTextField9;
	private JTextField jTextField10;
	private JTextField jTextField11;
	private JLabel jLabel4;
	private JLabel jLabel5;
	private JTextField jTextField12;
	private JTextField jTextField13;
	private JLabel jLabel6;
	private JLabel jLabel7;
	private JCheckBox jCheckBox5;
	private JCheckBox jCheckBox2;
	private JCheckBox jCheckBox3;
	private JCheckBox jCheckBox4;
	private JCheckBox jCheckBox7;
	private JCheckBox jCheckBox8;
	private JCheckBox jCheckBox6;
	private JTextField jTextField17;
	private JTextField jTextField15;
	private JTextField jTextField14;
	private JTextField jTextField16;
	private JPanel jPanel3;
	private JLabel jLabel8;
	private JLabel jLabel9;
	private JLabel jLabel10;
	private JLabel jLabel11;
	private JTextField jTextField18;
	private JPanel jPanel2;
	private JCheckBox jCheckBox9;
	private JCheckBox jCheckBox10;
	private JCheckBox jCheckBox11;
	private JCheckBox jCheckBox12;
	private JTextField jTextField19;
	private JTextField jTextField20;
	private JLabel jLabel12;
	private JLabel jLabel13;
	public Window2() {
		initComponents();
	}

	private void initComponents() {
		setLayout(new GroupLayout());
		add(getJTabbedPane0(), new Constraints(new Bilateral(0, 0, 5), new Bilateral(0, 0, 7)));
		setSize(320, 240);
		setTitle("Data Window");
	}

	private JLabel getJLabel13() {
		if (jLabel13 == null) {
			jLabel13 = new JLabel();
			jLabel13.setText("dy");
		}
		return jLabel13;
	}

	private JLabel getJLabel12() {
		if (jLabel12 == null) {
			jLabel12 = new JLabel();
			jLabel12.setText("dx");
		}
		return jLabel12;
	}

	private JTextField getJTextField20() {
		if (jTextField20 == null) {
			jTextField20 = new JTextField();
			jTextField20.setText("0");
		}
		return jTextField20;
	}

	private JTextField getJTextField19() {
		if (jTextField19 == null) {
			jTextField19 = new JTextField();
			jTextField19.setText("0");
		}
		return jTextField19;
	}

	private JCheckBox getJCheckBox12() {
		if (jCheckBox12 == null) {
			jCheckBox12 = new JCheckBox();
			jCheckBox12.setText("空中判定");
		}
		return jCheckBox12;
	}

	private JCheckBox getJCheckBox11() {
		if (jCheckBox11 == null) {
			jCheckBox11 = new JCheckBox();
			jCheckBox11.setText("行動可能");
		}
		return jCheckBox11;
	}

	private JCheckBox getJCheckBox10() {
		if (jCheckBox10 == null) {
			jCheckBox10 = new JCheckBox();
			jCheckBox10.setText("ガード可能");
		}
		return jCheckBox10;
	}

	private JCheckBox getJCheckBox9() {
		if (jCheckBox9 == null) {
			jCheckBox9 = new JCheckBox();
			jCheckBox9.setText("投げ無敵");
		}
		return jCheckBox9;
	}

	private JPanel getJPanel2() {
		if (jPanel2 == null) {
			jPanel2 = new JPanel();
			jPanel2.setLayout(new GroupLayout());
			jPanel2.add(getJTextField18(), new Constraints(new Leading(42, 82, 10, 10), new Leading(12, 12, 12)));
			jPanel2.add(getJLabel11(), new Constraints(new Leading(12, 12, 12), new Leading(14, 12, 12)));
			jPanel2.add(getJTextField19(), new Constraints(new Leading(42, 82, 12, 12), new Leading(36, 48, 48)));
			jPanel2.add(getJTextField20(), new Constraints(new Leading(42, 82, 12, 12), new Leading(62, 48, 48)));
			jPanel2.add(getJLabel12(), new Constraints(new Leading(12, 12, 12), new Leading(38, 48, 48)));
			jPanel2.add(getJLabel13(), new Constraints(new Leading(12, 12, 12), new Leading(64, 48, 48)));
			jPanel2.add(getJCheckBox10(), new Constraints(new Leading(38, 12, 12), new Leading(88, 90, 90)));
			jPanel2.add(getJCheckBox11(), new Constraints(new Leading(134, 12, 12), new Leading(88, 12, 12)));
			jPanel2.add(getJCheckBox9(), new Constraints(new Leading(134, 12, 12), new Leading(113, 12, 12)));
			jPanel2.add(getJCheckBox12(), new Constraints(new Leading(38, 12, 12), new Leading(113, 12, 12)));
		}
		return jPanel2;
	}

	private JTextField getJTextField18() {
		if (jTextField18 == null) {
			jTextField18 = new JTextField();
			jTextField18.setText("0");
		}
		return jTextField18;
	}

	private JLabel getJLabel11() {
		if (jLabel11 == null) {
			jLabel11 = new JLabel();
			jLabel11.setText("axis");
		}
		return jLabel11;
	}

	private JLabel getJLabel10() {
		if (jLabel10 == null) {
			jLabel10 = new JLabel();
			jLabel10.setText("Y");
		}
		return jLabel10;
	}

	private JLabel getJLabel9() {
		if (jLabel9 == null) {
			jLabel9 = new JLabel();
			jLabel9.setText("X");
		}
		return jLabel9;
	}

	private JLabel getJLabel8() {
		if (jLabel8 == null) {
			jLabel8 = new JLabel();
		}
		return jLabel8;
	}

	private JPanel getJPanel3() {
		if (jPanel3 == null) {
			jPanel3 = new JPanel();
			jPanel3.setVisible(false);
			jPanel3.setLayout(new GroupLayout());
			jPanel3.add(getJTextField17(), new Constraints(new Leading(42, 82, 10, 10), new Leading(12, 12, 12)));
			jPanel3.add(getJTextField15(), new Constraints(new Leading(136, 82, 10, 10), new Leading(12, 12, 12)));
			jPanel3.add(getJTextField14(), new Constraints(new Leading(42, 82, 12, 12), new Leading(38, 12, 12)));
			jPanel3.add(getJTextField16(), new Constraints(new Leading(136, 82, 12, 12), new Leading(38, 12, 12)));
			jPanel3.add(getJLabel8(), new Constraints(new Leading(29, -20, 10, 10), new Leading(34, -20, 10, 10)));
			jPanel3.add(getJLabel9(), new Constraints(new Leading(14, 32, 10, 10), new Leading(14, 12, 12)));
			jPanel3.add(getJLabel10(), new Constraints(new Leading(14, 12, 12), new Leading(40, 12, 12)));
		}
		return jPanel3;
	}

	private JTextField getJTextField16() {
		if (jTextField16 == null) {
			jTextField16 = new JTextField();
			jTextField16.setText("0");
		}
		return jTextField16;
	}

	private JTextField getJTextField14() {
		if (jTextField14 == null) {
			jTextField14 = new JTextField();
			jTextField14.setText("0");
		}
		return jTextField14;
	}

	private JTextField getJTextField15() {
		if (jTextField15 == null) {
			jTextField15 = new JTextField();
			jTextField15.setText("0");
		}
		return jTextField15;
	}

	private JTextField getJTextField17() {
		if (jTextField17 == null) {
			jTextField17 = new JTextField();
			jTextField17.setText("0");
		}
		return jTextField17;
	}

	private JCheckBox getJCheckBox6() {
		if (jCheckBox6 == null) {
			jCheckBox6 = new JCheckBox();
			jCheckBox6.setText("ロック");
		}
		return jCheckBox6;
	}

	private JCheckBox getJCheckBox8() {
		if (jCheckBox8 == null) {
			jCheckBox8 = new JCheckBox();
			jCheckBox8.setText("強制ダウン");
		}
		return jCheckBox8;
	}

	private JCheckBox getJCheckBox7() {
		if (jCheckBox7 == null) {
			jCheckBox7 = new JCheckBox();
			jCheckBox7.setText("中段");
		}
		return jCheckBox7;
	}

	private JCheckBox getJCheckBox4() {
		if (jCheckBox4 == null) {
			jCheckBox4 = new JCheckBox();
			jCheckBox4.setText("下段");
		}
		return jCheckBox4;
	}

	private JCheckBox getJCheckBox3() {
		if (jCheckBox3 == null) {
			jCheckBox3 = new JCheckBox();
			jCheckBox3.setText("投げ");
		}
		return jCheckBox3;
	}

	private JCheckBox getJCheckBox2() {
		if (jCheckBox2 == null) {
			jCheckBox2 = new JCheckBox();
			jCheckBox2.setText("特殊");
		}
		return jCheckBox2;
	}

	private JCheckBox getJCheckBox5() {
		if (jCheckBox5 == null) {
			jCheckBox5 = new JCheckBox();
			jCheckBox5.setText("打撃");
		}
		return jCheckBox5;
	}

	private JLabel getJLabel7() {
		if (jLabel7 == null) {
			jLabel7 = new JLabel();
			jLabel7.setText("damage");
		}
		return jLabel7;
	}

	private JLabel getJLabel6() {
		if (jLabel6 == null) {
			jLabel6 = new JLabel();
			jLabel6.setText("point");
		}
		return jLabel6;
	}

	private JTextField getJTextField13() {
		if (jTextField13 == null) {
			jTextField13 = new JTextField();
			jTextField13.setText("0");
		}
		return jTextField13;
	}

	private JTextField getJTextField12() {
		if (jTextField12 == null) {
			jTextField12 = new JTextField();
			jTextField12.setText("0");
		}
		return jTextField12;
	}

	private JLabel getJLabel5() {
		if (jLabel5 == null) {
			jLabel5 = new JLabel();
			jLabel5.setText("g");
		}
		return jLabel5;
	}

	private JLabel getJLabel4() {
		if (jLabel4 == null) {
			jLabel4 = new JLabel();
			jLabel4.setText("air");
		}
		return jLabel4;
	}

	private JTextField getJTextField11() {
		if (jTextField11 == null) {
			jTextField11 = new JTextField();
			jTextField11.setText("0");
		}
		return jTextField11;
	}

	private JTextField getJTextField10() {
		if (jTextField10 == null) {
			jTextField10 = new JTextField();
			jTextField10.setText("0");
		}
		return jTextField10;
	}

	private JTextField getJTextField9() {
		if (jTextField9 == null) {
			jTextField9 = new JTextField();
			jTextField9.setText("0");
		}
		return jTextField9;
	}

	private JTextField getJTextField8() {
		if (jTextField8 == null) {
			jTextField8 = new JTextField();
			jTextField8.setText("0");
		}
		return jTextField8;
	}

	private JLabel getJLabel3() {
		if (jLabel3 == null) {
			jLabel3 = new JLabel();
			jLabel3.setText("Y");
		}
		return jLabel3;
	}

	private JLabel getJLabel2() {
		if (jLabel2 == null) {
			jLabel2 = new JLabel();
			jLabel2.setText("X");
		}
		return jLabel2;
	}

	private JTextField getJTextField7() {
		if (jTextField7 == null) {
			jTextField7 = new JTextField();
			jTextField7.setText("0");
		}
		return jTextField7;
	}

	private JTextField getJTextField6() {
		if (jTextField6 == null) {
			jTextField6 = new JTextField();
			jTextField6.setText("0");
		}
		return jTextField6;
	}

	private JTextField getJTextField5() {
		if (jTextField5 == null) {
			jTextField5 = new JTextField();
			jTextField5.setText("0");
		}
		return jTextField5;
	}

	private JTextField getJTextField4() {
		if (jTextField4 == null) {
			jTextField4 = new JTextField();
			jTextField4.setText("0");
		}
		return jTextField4;
	}

	private JPanel getJPanel1() {
		if (jPanel1 == null) {
			jPanel1 = new JPanel();
			jPanel1.setLayout(new GroupLayout());
			jPanel1.add(getJTextField4(), new Constraints(new Leading(42, 82, 12, 12), new Leading(12, 12, 12)));
			jPanel1.add(getJTextField5(), new Constraints(new Leading(136, 82, 12, 12), new Leading(12, 12, 12)));
			jPanel1.add(getJTextField6(), new Constraints(new Leading(42, 82, 12, 12), new Leading(40, 10, 10)));
			jPanel1.add(getJTextField7(), new Constraints(new Leading(136, 82, 12, 12), new Leading(40, 12, 12)));
			jPanel1.add(getJLabel2(), new Constraints(new Leading(12, 20, 12, 12), new Leading(14, 12, 12)));
			jPanel1.add(getJLabel3(), new Constraints(new Leading(12, 40, 12, 12), new Leading(42, 12, 12)));
			jPanel1.add(getJTextField8(), new Constraints(new Leading(42, 82, 12, 12), new Leading(66, 12, 12)));
			jPanel1.add(getJTextField9(), new Constraints(new Leading(136, 82, 12, 12), new Leading(66, 48, 48)));
			jPanel1.add(getJTextField10(), new Constraints(new Leading(42, 82, 12, 12), new Leading(92, 12, 12)));
			jPanel1.add(getJTextField11(), new Constraints(new Leading(136, 82, 12, 12), new Leading(92, 48, 48)));
			jPanel1.add(getJLabel4(), new Constraints(new Leading(12, 30, 12, 12), new Leading(68, 12, 12)));
			jPanel1.add(getJLabel5(), new Constraints(new Leading(12, 35, 12, 12), new Leading(94, 12, 12)));
			jPanel1.add(getJTextField12(), new Constraints(new Leading(264, 45, 10, 10), new Leading(12, 12, 12)));
			jPanel1.add(getJTextField13(), new Constraints(new Leading(263, 46, 12, 12), new Leading(40, 12, 12)));
			jPanel1.add(getJLabel6(), new Constraints(new Leading(230, 12, 12), new Leading(14, 48, 48)));
			jPanel1.add(getJLabel7(), new Constraints(new Leading(218, 10, 10), new Leading(42, 48, 48)));
			jPanel1.add(getJCheckBox5(), new Constraints(new Leading(42, 12, 12), new Leading(118, 12, 12)));
			jPanel1.add(getJCheckBox2(), new Constraints(new Leading(42, 12, 12), new Leading(148, 12, 12)));
			jPanel1.add(getJCheckBox3(), new Constraints(new Leading(42, 12, 12), new Leading(178, 12, 12)));
			jPanel1.add(getJCheckBox4(), new Constraints(new Leading(94, 10, 10), new Leading(118, 12, 12)));
			jPanel1.add(getJCheckBox7(), new Constraints(new Leading(94, 12, 12), new Leading(148, 12, 12)));
			jPanel1.add(getJCheckBox8(), new Constraints(new Leading(151, 12, 12), new Leading(148, 12, 12)));
			jPanel1.add(getJCheckBox6(), new Constraints(new Leading(151, 12, 12), new Leading(118, 12, 12)));
		}
		return jPanel1;
	}

	private JLabel getJLabel1() {
		if (jLabel1 == null) {
			jLabel1 = new JLabel();
			jLabel1.setText("Y");
		}
		return jLabel1;
	}

	private JTextField getJTextField3() {
		if (jTextField3 == null) {
			jTextField3 = new JTextField();
			jTextField3.setText("0");
		}
		return jTextField3;
	}

	private JTextField getJTextField2() {
		if (jTextField2 == null) {
			jTextField2 = new JTextField();
			jTextField2.setText("0");
		}
		return jTextField2;
	}

	private JLabel getJLabel0() {
		if (jLabel0 == null) {
			jLabel0 = new JLabel();
			jLabel0.setText("X");
		}
		return jLabel0;
	}

	private JTextField getJTextField1() {
		if (jTextField1 == null) {
			jTextField1 = new JTextField();
			jTextField1.setText("0");
		}
		return jTextField1;
	}

	private JTextField getJTextField0() {
		if (jTextField0 == null) {
			jTextField0 = new JTextField();
			jTextField0.setText("0");
		}
		return jTextField0;
	}

	private JCheckBox getJCheckBox1() {
		if (jCheckBox1 == null) {
			jCheckBox1 = new JCheckBox();
			jCheckBox1.setText("特殊無敵");
		}
		return jCheckBox1;
	}

	private JTabbedPane getJTabbedPane0() {
		if (jTabbedPane0 == null) {
			jTabbedPane0 = new JTabbedPane();
			jTabbedPane0.addTab("Hit", getJPanel0());
			jTabbedPane0.addTab("Attack", getJPanel1());
			jTabbedPane0.addTab("Push", getJPanel3());
			jTabbedPane0.addTab("State", getJPanel2());
		}
		return jTabbedPane0;
	}

	private JPanel getJPanel0() {
		if (jPanel0 == null) {
			jPanel0 = new JPanel();
			jPanel0.setVisible(false);
			jPanel0.setLayout(new GroupLayout());
			jPanel0.add(getJTextField0(), new Constraints(new Leading(42, 82, 10, 10), new Leading(12, 12, 12)));
			jPanel0.add(getJTextField1(), new Constraints(new Leading(136, 82, 10, 10), new Leading(12, 12, 12)));
			jPanel0.add(getJLabel0(), new Constraints(new Leading(16, 20, 12, 12), new Leading(14, 12, 12)));
			jPanel0.add(getJTextField2(), new Constraints(new Leading(42, 82, 12, 12), new Leading(36, 12, 12)));
			jPanel0.add(getJTextField3(), new Constraints(new Leading(136, 82, 12, 12), new Leading(36, 12, 12)));
			jPanel0.add(getJLabel1(), new Constraints(new Leading(16, 20, 12, 12), new Leading(38, 12, 12)));
			jPanel0.add(getJCheckBox0(), new Constraints(new Leading(42, 12, 12), new Leading(66, 12, 12)));
			jPanel0.add(getJCheckBox1(), new Constraints(new Leading(131, 12, 12), new Leading(66, 12, 12)));
		}
		return jPanel0;
	}

	private JCheckBox getJCheckBox0() {
		if (jCheckBox0 == null) {
			jCheckBox0 = new JCheckBox();
			jCheckBox0.setText("打撃無敵");
		}
		return jCheckBox0;
	}
}
