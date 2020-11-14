
import java.util.HashMap;
import java.util.Map;

public class QuaternionToEuler extends QuaternionData {
	private double square_w;
	private double square_x;
	private double square_y;
	private double square_z;
	private double square_sum;
	private double origin_sum;
	private double siny_cosp;
	private double cosy_cosp;
	private Map<String,Double> map_quaternion;


	public QuaternionToEuler() {
		settingQuaternionData();
		settingQuaternionToEuler();
		map_quaternion=new HashMap<String,Double>();
	}

	public Map<String,Double> QuaternionToEulerAngles() {
		squareQuaternion();
		 square_sum = square_x + square_y + square_z + square_w;
		 origin_sum = x * y + z * w;
		if (origin_sum > 0.499 * square_sum) {
			roll=2*Math.atan2(x, w);
			pitch = Math.PI / 2;
			yaw = 0;
			map_quaternion.put("roll", roll);
			map_quaternion.put("pitch", pitch);
			map_quaternion.put("yaw",yaw);
			return map_quaternion;
		}
		else if (origin_sum < -0.499) {
			roll = -2 * Math.atan2(x, w);
			pitch = -Math.PI / 2;
			yaw = 0;
			map_quaternion.put("roll", roll);
			map_quaternion.put("pitch", pitch);
			map_quaternion.put("yaw",yaw);
			return map_quaternion;
		}
		roll = Math.atan2(2 * y * w - 2 * x * z, square_x - square_y - square_z + square_w);
		pitch = Math.asin(2 * origin_sum / square_sum);



		siny_cosp = 2 * (x * w - y * z);

		cosy_cosp = -x * x + y * y - z * z + w * w;
		yaw = Math.atan2(siny_cosp, cosy_cosp);
		map_quaternion.put("roll", roll);
		map_quaternion.put("pitch", pitch);
		map_quaternion.put("yaw",yaw);
		return map_quaternion;
	}

	public void squareQuaternion() {
		square_w = w * w;
		square_x = x * x;
		square_y = y * y;
		square_z = z * z;
	}

	private boolean settingQuaternionToEuler() {
		square_w = 0;
		square_x = 0;
		square_y = 0;
		square_z = 0;
		return true;
	}


	public void setterX(double setX) {
		x = setX;
	}

	public void setterY(double setY) {
		y = setY;
	}

	public void setterZ(double setZ) {
		z = setZ;
	}

	public void setterW(double setW) {
		w = setW;
	}

}
