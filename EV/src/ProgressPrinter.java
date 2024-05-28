import java.util.concurrent.atomic.AtomicLong;
public class ProgressPrinter {

    private final AtomicLong totalBytesRead;
    private final long contentLength;
    private final long startTime;

    public ProgressPrinter(AtomicLong totalBytesRead, long contentLength, long startTime) {
        this.totalBytesRead = totalBytesRead;
        this.contentLength = contentLength;
        this.startTime = startTime;
    }

    private static String getProgressBar(int percent) {
        int progressBarLength = 50;
        int filledLength = progressBarLength * percent / 100;
        StringBuilder bar = new StringBuilder();
        bar.append("[");
        for (int i = 0; i < progressBarLength; i++) {
            if (i < filledLength) {
                bar.append("=");
            } else {
                bar.append(" ");
            }
        }
        bar.append("]");
        return bar.toString();
    }

    public void print() {
        int percentCompleted = (int) (totalBytesRead.get() * 100 / contentLength);
        long elapsedTime = System.currentTimeMillis() - startTime;
        double downloadSpeed = totalBytesRead.get() / (elapsedTime / 1000.0); // bytes per second
        long remainingTime = (long) ((contentLength - totalBytesRead.get()) / downloadSpeed); // seconds

        String speedString;
        String timeString;

        if (downloadSpeed > 1024 * 1024) {
            speedString = String.format("%.2f MB/s", downloadSpeed / 1024 / 1024);
        } else {
            speedString = String.format("%.2f KB/s", downloadSpeed / 1024);
        }

        if (remainingTime > 60) {
            timeString = String.format("%dm%ds", remainingTime / 60, remainingTime % 60);
        } else {
            timeString = String.format("%ds", remainingTime);
        }

        String progressBar = getProgressBar(percentCompleted);
        System.out.printf("下载进度: %s %d%%, 已下载: %.2f/%.2f MB, 速度: %s, 剩余时间: %s\r",
                progressBar, percentCompleted, totalBytesRead.get() / 1024.0 / 1024.0,
                contentLength / 1024.0 / 1024.0, speedString, timeString);
    }
}