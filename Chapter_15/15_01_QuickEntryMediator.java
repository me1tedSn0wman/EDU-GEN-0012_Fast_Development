package utility;

import javax.swing.*;
import javax.swing.event.*;

public class QuickEntryMediator {
	public QuickEntryMediator(JTextField t, Jlist l)
	{
		itsTextField = t;
		itsList = l;
		
		itsTextField.getDocument().addDocumentListener(
			new DocumentListener() 
			{
				public void changedUpdate(DocumentEvent e) 
				{
					textFieldChanged();
				}
				
				public void insertUpdate(DocumentEvent e)
				{
					textFieldChanged();
				}
				
				public void removeUpdate(DocumentEvent e)
				{
					textFieldChanged();
				}
			}
		)
	}
	
	private void textFieldChanged() 
	{
		String prefix = itsTextField.getText();
		
		if(prefix.length() == 0) 
		{
			itsList.clearSelection();
			return;
		}
		
		ListModel m = itsList.getModel();
		boolean found = false;
		for(int i = 0; found == false && i < m.getSize(); i++)
		{
			Object o= m.getElementAt(i);
			String s = o.toString();
			if(s.startWith(prefix))
			{
				itsList.setSelectedValue(o,true);
				found = true;
			}
		}
		
		if(!found)
		{
			itsList.clearSelection();
		}
	}
	
	private JTextField itsTextField;
	private JList itsList;
	
}