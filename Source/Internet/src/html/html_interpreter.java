// html/html_interpreter.java
public class HTMLInterpreter {

    // Estrutura de linha com texto e cor
    public static class LineData {
        public String text;
        public int color;
        public String link; // se houver <a href>
        public LineData(String t, int c, String l) { text=t; color=c; link=l; }
    }

    public static LineData[] parseHTML(String html) {
        java.util.List<LineData> lines = new java.util.ArrayList<>();
        int colorDefault = 0xFFFFFF;
        int colorH1 = 0xFF0000;
        int colorBold = 0xFFFF00;
        int colorItalic = 0x00FF00;
        int colorLink = 0x00BFFF;

        String[] rawLines = html.split("\n");
        for(String l : rawLines) {
            String text = l.replaceAll("<[^>]*>", ""); // remove tags
            int color = colorDefault;
            String link = null;

            if (l.contains("<h1>")) color = colorH1;
            else if (l.contains("<b>")) color = colorBold;
            else if (l.contains("<i>")) color = colorItalic;
            else if (l.contains("<a href=\"")) {
                color = colorLink;
                int start = l.indexOf("<a href=\"")+9;
                int end = l.indexOf("\"", start);
                if(end>start) link = l.substring(start,end);
            }

            lines.add(new LineData(text, color, link));
        }

        return lines.toArray(new LineData[0]);
    }
}
