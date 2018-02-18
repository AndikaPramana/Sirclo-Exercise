<?php include "header.php"; ?>
    <hr>
    <!-- open form  -->
    <?php echo form_open("BodyWeightController/update/".$bodyrecord->Date); ?>
      <table cellpadding="5">
        <tr>
          <td><b>Date : </b></td>
          <td><b><?php echo $bodyrecord->Date; ?></b></td>
        </tr>
        <tr>
          <td><b>Max : </b></td>
          <td><b><?php echo $bodyrecord->Max; ?></b></td>
        </tr>
        <tr>
          <td><b>Min : </b></td>
          <td><b><?php echo $bodyrecord->Min; ?></b></td>
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
      <input type="submit" name="submit" value="Update">
    <?php echo form_close(); ?>
<?php include "footer.php"; ?>