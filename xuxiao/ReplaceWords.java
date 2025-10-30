import java.util.List;

public class ReplaceWords {
    public String replaceWords(List<String> dictionary, String sentence) {
        int index = -1;
        StringBuilder sb = new StringBuilder();
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; i++) {
            for(int j = 0; j < dictionary.size(); j++) {
                if(words[i].startsWith(dictionary.get(j))) {
                    if(index != -1) {
                        index = dictionary.get(index).length() < dictionary.get(j).length() ? j:index;
                    }
                    else{
                        index = j;
                    }
                }
            }
            if(index != -1) {
                sb.append(dictionary.get(index));
            }else{
                sb.append(words[i]);
            }
            if(i != words.length-1) {
                sb.append(" ");
            }
            index = -1;
        }
        return sb.toString();
    }
}
