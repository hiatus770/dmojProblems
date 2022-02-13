package LoveLetterDmoj;
import java.util.Scanner;  // Import the Scanner class


class Main {
  static int letter(char find, String alphabet){
    int found = 0; 
    for(int i = 0; i < 26; i++){
    if (alphabet.charAt(i) == find){
      found = i;
      break;  
    }
    }
    return found;
  }

  public static void main(String[] args) {
    String alphabet = "abcdefghijklmnopqrstuvwxyz"; 
    Scanner scan = new Scanner(System.in);  
    int shift = Integer.parseInt(scan.nextLine()); 
    String message = scan.nextLine();  
    for(int i = 0; i < message.length(); i++){
    if (message.charAt(i) != ' '){
      System.out.print(alphabet.charAt((letter(message.charAt(i), alphabet) + shift)%26));
    } else {
      System.out.print(" "); 
    }
    }
    System.out.println(); 
  }
}