// Student name: Kwok Man Hei
// Student ID  : 55229880

// Submission deadline: Friday, 23 Oct 2020, 11 am.

// Complete the implementation of class MorseCode and class Node.

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class MorseCode
{
    // Define the required instance variables.
     Node morseTreeRoot;
    public MorseCode(String filename) throws IOException
    {   morseTreeRoot = new Node('\0');
        // Read the code table from data file and set up the data structures.
        // You need not provide the exception hander in this method.
        Scanner scanner = null;
        try{
			scanner = new Scanner(new File(filename));
			String readLine;
			while (scanner.hasNextLine()){
				readLine = scanner.nextLine();
				String symbol = readLine.split("\t| ")[0];
				String code = readLine.split("\t| ")[1];
                                String intcode="";
				//add the input char and morse at this line to morseTree
                                Node current = morseTreeRoot;
                                for (int i=0; i<code.length(); i++){
			        if (code.substring(i, i+1).equals("."))
                                {
                                    intcode+="10";
				        if (current.getLeft() == null){
					 current.extendLeft('\0');
                                         
				}
				current = current.getLeft();
		         	}
		         	else if (code.substring(i, i+1).equals("-"))
                                {
                                    intcode+="1110";
			        	if (current.getRight() == null){
					 current.extendRight('\0');
                                         
				}
				current = current.getRight();
			}
		}
		current.setSymb(symbol.charAt(0));
                  current.setCode(code);
	}		   
		}
		finally {
			if (scanner != null) {
				scanner.close();
			}
		}
     
    }
    char findSymb(String code) 
    {
        Node current = morseTreeRoot;
		boolean exists = true;
		for (int i=0; (i<code.length() ); i++){
                    if (code.substring(i, i+1).equals("1"))
                    { if(i+3<=code.length())
                        {  if (code.substring(i, i+3).equals("111")){
				if (current.getRight() == null){
					exists = false;
				}
				current = current.getRight();
                                i+=3;
                                
			}
                         else {
				if (current.getLeft() == null){
					exists = false;
				}
				current = current.getLeft();
                             i++;
			}
                    }
                    else{ if (current.getLeft() == null){
					exists = false;
				}
				current = current.getLeft();
                              i++;
                    }
                }
		}
		if (exists){
			return current.getSymb();
		}
		return '!';
        // now deal with the node 
    } 
  public String search (Node current, char ltr,String s) {
        //char temp = current.setSymb();  //for debugging purposes
 
     if (current == null)         
         return null;

 
    if (current.getSymb()==ltr)
    {   
        return current.getCode();
    }
    
    /* then recur on left sutree */
    String res1 = search(current.getLeft(),ltr,s);
    // node found, no need to look further
    if(res1!=null) return res1; 
 
    /* node is not found in left, 
    so recur on right subtree */
    String res2 = search(current.getRight(), ltr,s);
 
    return res2;
  }
    public String encode(String text)
    {
        // Return a String of '0' and '1' that represents the Morse code
        // of the input text.
        // Input text may contain uppercase letters, digits, and space char.
        
        
        // Your codes
      Node current = morseTreeRoot;
        String result = "";

        char ltr;

        for (int i = 0; i < text.length(); i++) {
            String s = null;
            ltr = text.charAt(i);
            if(ltr!=' '){
             String encryCode;
             encryCode=search(current,ltr, s);
             for(int j=0; j<encryCode.length();j++)
                 if(encryCode.charAt(j)=='.')
                     result+="10";
                 else 
                     result+="1110";
            }
            else
            result+="0000000";
            result+="00";
        }
        result=result.substring(0,result.length()-3);
       return result;
       // return result.substring(0,result.length()-1);

    }
    
    public String decode(String mc)
    {
        // mc is a sequence of '0' and '1' that represents the Morse code of a message.
        // Return the decoded message as a String.
        
        
        // Your codes.
        // An efficient approach to do the decoding is to represent the code table by a binary tree.
        // If you use a brute-force approach in your answer, you will get lower marks.
             String decodedLine = "";
             for (String encodedWord : mc.split("0000000")){
		for (String encodedCharacter : encodedWord .split("000")){
	         	if (encodedCharacter.equals("|"))
                        {
				decodedLine += " ";	
                        }
			else if (encodedCharacter.length() > 0){
				char decodedCharacter = findSymb(encodedCharacter);
				if (decodedCharacter == '!'){
						System.out.println("effor char found: "+encodedCharacter);
						}
						else{
							decodedLine += decodedCharacter;
						}
					}
                        
				}
                decodedLine +=" ";
             }
	
			
        return decodedLine;  // dummy return statement, replace it by your own codes
    } 
       
    // Other supporting methods where appropriate.
}

// --------------------------------------------------------------------------------

// class to model a tree node to support decoding of Morse code
class Node
{
    private char symb;
    private String Mcode;
    private Node left, right;
    
    public Node(char c)
    {
        Mcode=null;
        symb = c;
        left = right = null;
    }
    
    // other methods
public Node getLeft(){return this.left;}
public Node getRight(){return this.right;}
public char getSymb(){return this.symb;}
public void setSymb(char c){this.symb=c;}
public String getCode(){return this.Mcode;}
public void setCode(String s){this.Mcode=s;}
    //  Hint: a method to create the left child of the implicit Node with symbol c.

    public void extendLeft(char c)
    {
        left = new Node(c);
    }
public void extendRight(char c)
    {
        right = new Node(c);
    }

}