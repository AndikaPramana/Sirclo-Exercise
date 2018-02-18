<?php include "header.php"; ?>

<h2>Add a Daily Record</h2>

<!-- open form  -->
<?php echo form_open("BodyWeightController/create/"); ?>
<hr>
	<table cellpadding="5">
        <tr>
          <td><b>Date : </b></td>
          <td><input type="text" name="input_Date" value=""></td>
        </tr>
        <tr>
          <td>New Max : </td>
          <td><input type="text" name="input_Max" value=""></td>
        </tr>
        <tr>
          <td>New Min : </td>
          <td><input type="text" name="input_Min" value=""></td>
        </tr>
      </table>
      <hr>
	<input type="submit" name="submit" value="Add this record">
<?php echo form_close(); ?>

<?php include "footer.php"; ?>
